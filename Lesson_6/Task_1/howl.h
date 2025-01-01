#ifndef HOWL_H
#define HOWL_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMenu>
#include <QAction>
#include <QTime>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class Howl;
}
QT_END_NAMESPACE

class Howl : public QMainWindow
{
    Q_OBJECT

public:
    Howl(QWidget *parent = nullptr);
    ~Howl();

private slots:
    void selectFiles();

    void setVolumeText(int volume);
    void setMedia(QString text);

    void setProgress(qint64 progress);
    void setVolume(int volume);
    void playStateChanged(QMediaPlayer::PlaybackState state);

    void nextTrack();
    void previousTrack();

    void mediaStatusChanged(QMediaPlayer::MediaStatus status);

    void updatePosition(qint64 position);
    void updateDuration(qint64 duration);
    void changePosition(qint64 position);

    void createNewPlaylist();
    void savePlaylist();
    void loadPlaylist();

private:
    Ui::Howl *ui;
    QMenu *m_file;
    QAction *m_select;

    QMenu *m_playlistMenu;
    QAction *m_newPlaylist;
    QAction *m_savePlaylist;
    QAction *m_loadPlaylist;

    const int c_startVolume = 50;

    QMediaPlayer *m_player;
    QAudioOutput *m_audioOutput;
};
#endif // HOWL_H
