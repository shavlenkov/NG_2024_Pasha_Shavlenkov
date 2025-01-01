#include "howl.h"
#include "ui_howl.h"

Howl::Howl(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Howl)
{
    ui->setupUi(this);

    m_file = new QMenu("File");
    m_select = new QAction("Select Files");

    m_file->addAction(m_select);
    ui->menubar->addMenu(m_file);

    m_audioOutput = new QAudioOutput();
    m_player = new QMediaPlayer();

    m_playlistMenu = menuBar()->addMenu("Playlist");

    m_newPlaylist = new QAction("New Playlist", this);
    m_savePlaylist = new QAction("Save Playlist", this);
    m_loadPlaylist = new QAction("Load Playlist", this);

    m_playlistMenu->addAction(m_newPlaylist);
    m_playlistMenu->addAction(m_savePlaylist);
    m_playlistMenu->addAction(m_loadPlaylist);

    m_player->setAudioOutput(m_audioOutput);

    ui->sl_volume->setRange(0, 100);

    connect(m_player, &QMediaPlayer::playbackStateChanged, this, &Howl::playStateChanged);
    connect(ui->b_play, &QPushButton::clicked, m_player, &QMediaPlayer::play);

    connect(m_select, &QAction::triggered, this, &Howl::selectFiles);

    connect(ui->sl_volume, &QSlider::valueChanged, this, &Howl::setVolume);
    connect(ui->sl_volume, &QSlider::valueChanged, this, &Howl::setVolumeText);

    connect(ui->lw_playlist, &QListWidget::currentTextChanged, this, &Howl::setMedia);

    connect(ui->b_previous, &QPushButton::clicked, this, &Howl::previousTrack);
    connect(ui->b_next, &QPushButton::clicked, this, &Howl::nextTrack);

    connect(m_player, &QMediaPlayer::mediaStatusChanged, this, &Howl::mediaStatusChanged);

    connect(m_player, &QMediaPlayer::positionChanged, this, &Howl::updatePosition);
    connect(m_player, &QMediaPlayer::durationChanged, this, &Howl::updateDuration);
    connect(ui->s_progress, &QSlider::sliderMoved, this, &Howl::changePosition);

    connect(m_newPlaylist, &QAction::triggered, this, &Howl::createNewPlaylist);
    connect(m_savePlaylist, &QAction::triggered, this, &Howl::savePlaylist);
    connect(m_loadPlaylist, &QAction::triggered, this, &Howl::loadPlaylist);

    ui->sl_volume->setValue(c_startVolume);
    m_audioOutput->setVolume((float)c_startVolume / 100);
}

Howl::~Howl()
{
    delete m_file;
    delete m_select;

    m_player->stop();
    delete m_player;

    delete ui;
}

void Howl::selectFiles()
{
    QStringList files = QFileDialog::getOpenFileNames(
        this,
        "Select one or more files to open",
        "",
        "Music (*.mp3)");

    ui->lw_playlist->clear();
    ui->lw_playlist->addItems(files);
}

void Howl::setVolumeText(int volume)
{
    ui->l_volume->setText(QString::number(volume));
}

void Howl::setMedia(QString text)
{
    m_player->setSource(QUrl::fromLocalFile(text));
    ui->l_name->setText(text.remove(0, text.lastIndexOf("/")+1));
}

void Howl::setProgress(qint64 progress)
{
    ui->s_progress->setValue(progress / (m_player->duration()/100));
}

void Howl::setVolume(int volume)
{
    m_audioOutput->setVolume(((float)volume)/100);
}

void Howl::playStateChanged(QMediaPlayer::PlaybackState state)
{
    switch(state) {
        case QMediaPlayer::PlayingState: {
            disconnect (ui->b_play, &QPushButton::clicked, m_player, &QMediaPlayer::play);
            connect (ui->b_play, &QPushButton::clicked, m_player, &QMediaPlayer::pause);
            ui->b_play->setText("||");
        } break;
        case QMediaPlayer::PausedState: {
            ui->b_play->setText(">");
            disconnect (ui->b_play, &QPushButton::clicked, m_player, &QMediaPlayer::pause);
            connect (ui->b_play, &QPushButton::clicked, m_player, &QMediaPlayer::play);
        } break;
        case QMediaPlayer::StoppedState: {
            ui->b_play->setText(">");
            disconnect (ui->b_play, &QPushButton::clicked, m_player, &QMediaPlayer::pause);
            connect (ui->b_play, &QPushButton::clicked, m_player, &QMediaPlayer::play);
        } break;
    }
}

void Howl::previousTrack()
{
    int currentRow = ui->lw_playlist->currentRow();

    if(currentRow > 0) {
        ui->lw_playlist->setCurrentRow(currentRow - 1);
    } else {
        ui->lw_playlist->setCurrentRow(ui->lw_playlist->count() - 1);
    }

    m_player->play();
}

void Howl::nextTrack()
{
    int currentRow = ui->lw_playlist->currentRow();

    if(currentRow < ui->lw_playlist->count() - 1) {
        ui->lw_playlist->setCurrentRow(currentRow + 1);
    } else {
        ui->lw_playlist->setCurrentRow(0);
    }

    m_player->play();
}

void Howl::mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if(status == QMediaPlayer::EndOfMedia) {
        nextTrack();
    }
}

void Howl::updatePosition(qint64 position)
{
    ui->s_progress->setValue(position);

    QTime currentTime(0, (position / 60000) % 60, (position / 1000) % 60);

    ui->label_current_time->setText(currentTime.toString("mm:ss"));
}

void Howl::updateDuration(qint64 duration)
{
    ui->s_progress->setMaximum(duration);

    QTime totalTime(0, (duration / 60000) % 60, (duration / 1000) % 60);

    ui->label_total_time->setText(totalTime.toString("mm:ss"));
}

void Howl::changePosition(qint64 position)
{
    m_player->setPosition(position);
}

void Howl::createNewPlaylist()
{
    ui->lw_playlist->clear();
}

void Howl::savePlaylist()
{
    if(ui->lw_playlist->count() == 0) {
        QMessageBox::warning(this, "Warning", "The playlist is empty!");

        return;
    }

    QJsonArray playlistArray = {};

    for(int counter = 0; counter < ui->lw_playlist->count(); counter++) {
        QString filePath = ui->lw_playlist->item(counter)->text();

        QJsonObject trackObject = {};

        trackObject["name"] = filePath.section('/', -1);
        trackObject["path"] = filePath;

        playlistArray.append(trackObject);
    }

    QJsonDocument playlistDoc(playlistArray);

    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Save Playlist",
        "",
        "JSON Files (*.json)"
    );

    if(fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "Error", "Could not save playlist!");

        return;
    }

    file.write(playlistDoc.toJson(QJsonDocument::Indented));
    file.close();

    QMessageBox::information(this, "Success", "Playlist saved successfully!");
}

void Howl::loadPlaylist()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Load Playlist",
        "",
        "JSON Files (*.json)"
    );

    if(fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Could not open playlist file!");

        return;
    }

    QByteArray fileContent = file.readAll();
    file.close();

    QJsonDocument playlistDoc = QJsonDocument::fromJson(fileContent);

    if(!playlistDoc.isArray()) {
        QMessageBox::critical(this, "Error", "Invalid playlist format!");

        return;
    }

    QJsonArray playlistArray = playlistDoc.array();

    ui->lw_playlist->clear();

    for(int counter = 0; counter < playlistArray.count(); counter++) {
        QString trackPath = playlistArray[counter].toObject().value("path").toString();

        if(!trackPath.isEmpty()) {
            ui->lw_playlist->addItem(trackPath);
        }
    }

    QMessageBox::information(this, "Success", "Playlist loaded successfully!");
}
