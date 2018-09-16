#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SoundSelectionDialog.h"
#include "AppStrings.h"
#include <QDebug>


MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
    ui -> soundLoopPathLabel -> setText(Strings::MainWindow_NoSelectedFile);

    makeConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateSoundList()
{
    ui -> additionalSoundsListWidget -> clear();
    const QStringList& additionalSounds = m_model.additionalSounds();
    for (QString sound : additionalSounds)
    {
        ui -> additionalSoundsListWidget -> addItem(sound);
    }
}

void MainWindow::makeConnections()
{
    // Set main loop sound.
    connect
    (
        ui -> soundLoopBrowseButton,
        &QPushButton::clicked,
        [=](bool)
        {
            SoundSelectionDialog dialog(this);

            QStringList fileNames;
            if (dialog.exec())
            {
                fileNames = dialog.selectedFiles();
            }

            if (fileNames.size() == 0)
            {
                return;
            }

            Q_ASSERT(fileNames.size() == 1) ;
            m_model.defineMainSoundLoopPath(fileNames[0]);
            ui -> soundLoopPathLabel -> setText(m_model.mainSoundLoopPath());

        }
    );

    // Reset main loop sound.
    connect
    (
        ui -> soundLoopRemoveButton,
        &QPushButton::clicked,
        [=](bool)
        {
            m_model.clearMainSoundLoopPath();
            ui -> soundLoopPathLabel -> setText(Strings::MainWindow_NoSelectedFile);
        }
    );

    // Add sounds.
    connect
    (
        ui -> addSoundsButton,
        &QPushButton::clicked,
        [=](bool)
        {
            SoundSelectionDialog dialog(this);
            dialog.setFileMode(QFileDialog::ExistingFiles);

            QStringList fileNames;
            if (dialog.exec())
            {
                fileNames = dialog.selectedFiles();
            }

            for (QString path : fileNames)
            {
                m_model.addAdditionalSoundPath(path);
            }

            updateSoundList();
        }
    );

    // Remove a sound.
    connect
    (
        ui -> removeSoundButton,
        &QPushButton::clicked,
        [=](bool)
        {
            int selection = ui -> additionalSoundsListWidget -> currentRow();
            m_model.removeAdditionalSoundPath(selection);
            updateSoundList();
        }
    );

    // Clear all sounds.
    connect
    (
        ui -> clearButton,
        &QPushButton::clicked,
        [=](bool)
        {
            m_model.clearMainSoundLoopPath();
            m_model.clearAdditionalSoundPaths();

            ui -> soundLoopPathLabel -> setText(Strings::MainWindow_NoSelectedFile);
            updateSoundList();
        }
    );
}
