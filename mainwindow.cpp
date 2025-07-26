#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSettings>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , totalTasks(0)
    , completedTasks(0)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);


    // load saved tasks
    loadTasks();

    // Connect buttons and task change signal
    connect(ui->addtask, &QPushButton::clicked, this, &MainWindow::handleAddTaskButton);
    connect(ui->finishbtn, &QPushButton::clicked, this, &MainWindow::handleFinishButton);
    connect(ui->taskDisplay, &QListWidget::itemChanged, this, &MainWindow::handleTaskItemChanged);
    connect(ui->enterTask, &QLineEdit::returnPressed, this, &MainWindow::handleAddTaskButton);

    // Timer to update calendarCard every minute
    dateTimer = new QTimer(this);
    connect(dateTimer, &QTimer::timeout, this, &MainWindow::updateCalendarCard);
    dateTimer->start(1000); // update every 1 second

    // Call once immediately on startup
    updateCalendarCard();

    connect(ui->taskDisplay, &QListWidget::itemDoubleClicked,
            this, &MainWindow::handleTaskDoubleClick);


    QSettings settings("MyCompany", "MyApp");
    int size = settings.beginReadArray("tasks");

    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        QString text = settings.value("text").toString();
        bool isCompleted = settings.value("isCompleted").toBool();

        QListWidgetItem *item = new QListWidgetItem(text);
        QFont font = item->font();
        font.setStrikeOut(isCompleted);
        item->setFont(font);

        ui->taskDisplay->addItem(item);
    }

    settings.endArray();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleAddTaskButton()
{
    QString taskText = ui->enterTask->text().trimmed();

    if (!taskText.isEmpty()) {


        // Format with bullet
        QString formattedText = "• " + taskText;

        QListWidgetItem *item = new QListWidgetItem(formattedText);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);

        ui->taskDisplay->addItem(item);

        totalTasks++;
        updateProgressBar();
        ui->enterTask->clear();
    }
}

void MainWindow::handleTaskItemChanged(QListWidgetItem *item)
{
    Q_UNUSED(item);

    completedTasks = 0;
    for (int i = 0; i < ui->taskDisplay->count(); ++i) {
        if (ui->taskDisplay->item(i)->checkState() == Qt::Checked) {
            completedTasks++;
        }
    }
    updateProgressBar();
}

void MainWindow::updateProgressBar()
{
    if (totalTasks == 0) {
        ui->progressBar->setValue(0);
    } else {
        int progress = static_cast<int>((static_cast<float>(completedTasks) / totalTasks) * 100);
        ui->progressBar->setValue(progress);
    }
}

void MainWindow::handleFinishButton()
{
    ui->taskDisplay->clear();
    ui->progressBar->setValue(0);
    totalTasks = 0;
    completedTasks = 0;
}

void MainWindow::updateCalendarCard()
{
    QDateTime current = QDateTime::currentDateTime();

    QString day = current.date().toString("dddd");   // Full weekday name
    QString date = current.date().toString("dd");    // Day as 01, 02...
    QString month = current.date().toString("MMMM"); // Full month name

    ui->dayLabel->setText(day);
    ui->dateCircle->setText(date);
    ui->monthLabel->setText(month);
}

void MainWindow::handleTaskDoubleClick(QListWidgetItem *item)
{
    if (!item) return;

    // Toggle strike-through style
    QFont font = item->font();
    bool isStruckThrough = font.strikeOut();
    font.setStrikeOut(!isStruckThrough);
    item->setFont(font);

    // Change font color based on strike-through status
    item->setForeground(!isStruckThrough ? Qt::gray : Qt::black);

    // Recalculate completed tasks after strike toggle
    completedTasks = 0;
    for (int i = 0; i < ui->taskDisplay->count(); ++i) {
        QListWidgetItem *task = ui->taskDisplay->item(i);
        if (task->font().strikeOut()) {
            completedTasks++;
        }
    }

    // Update progress bar based on current task status
    updateProgressBar();
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings(" ", "ToDoApp");
    settings.beginWriteArray("tasks");

    for (int i = 0; i < ui->taskDisplay->count(); ++i) {
        QListWidgetItem *item = ui->taskDisplay->item(i);
        settings.setArrayIndex(i);
        settings.setValue("text", item->text());
        settings.setValue("struck", item->font().strikeOut());
    }

    settings.endArray();
    QMainWindow::closeEvent(event);
}




void MainWindow::saveTasks()
{
    QSettings settings("MyCompany", "MyTodoApp");
    settings.beginWriteArray("tasks");

    int saveIndex = 0;

    for (int i = 0; i < ui->taskDisplay->count(); ++i) {
        QListWidgetItem *item = ui->taskDisplay->item(i);

        // Skip items that are striked through
        if (!item->font().strikeOut()) {
            settings.setArrayIndex(saveIndex++);
            settings.setValue("text", item->text());
        }
    }

    settings.endArray();
}




void MainWindow::loadTasks()
{
    QSettings settings(" ", "ToDoApp");
    int size = settings.beginReadArray("tasks");

    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        QString text = settings.value("text").toString();
        bool struck = settings.value("struck").toBool();

        QListWidgetItem *item = new QListWidgetItem(text);
        QFont font = item->font();
        font.setStrikeOut(struck);
        item->setFont(font);
        item->setForeground(struck ? Qt::gray : Qt::black);

        ui->taskDisplay->addItem(item);
        totalTasks++;
        if (struck) completedTasks++;
    }

    settings.endArray();
    updateProgressBar();
}




