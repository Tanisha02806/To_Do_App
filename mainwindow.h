#include <QMainWindow>
#include <QListWidgetItem>
#include <QTimer>
#include <QDateTime>
#include <QCloseEvent>
#include <QSettings>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleAddTaskButton();                 // Replaces on_addtask_clicked
    void handleFinishButton();                  // Replaces on_finishbtn_clicked
    void handleTaskItemChanged(QListWidgetItem *item); // Replaces on_taskdisplay_itemChanged
    void handleTaskDoubleClick(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    int totalTasks = 0;
    int completedTasks = 0;
    QTimer *dateTimer;
    void updateCalendarCard();

    void updateProgressBar();
    void saveTasks();
    void loadTasks();

protected:
    void closeEvent(QCloseEvent *event) override;
};
