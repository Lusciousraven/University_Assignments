#include "MainWindow.h"
#include "MusicModel.h"
#include "RatingDelegate.h"
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QTableView>
#include <QPushButton>
#include <QGridLayout>
#include <QHeaderView>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QWidget{parent},
    m_composerEdit{new QLineEdit},
    m_albumEdit{new QLineEdit},
    m_replacementCostSpinBox{new QDoubleSpinBox},
    m_ratingSpinBox{new QSpinBox},
    m_addButton{new QPushButton("Add")},
    m_deleteButton{new QPushButton("Delete")},
    m_tableView{new QTableView},
    m_model{new MusicModel(this)}
{
    setupGui();
    m_tableView->setModel(m_model);
    m_tableView->setItemDelegateForColumn(3, new RatingDelegate(this));

    connect(m_addButton, &QPushButton::clicked, this, &MainWindow::addCD);
    connect(m_deleteButton, &QPushButton::clicked, this, &MainWindow::deleteCD);
    connect(m_composerEdit, &QLineEdit::textChanged, this, &MainWindow::enableButton);
    connect(m_albumEdit, &QLineEdit::textChanged, this, &MainWindow::enableButton);
}

MainWindow::~MainWindow()
{
}

void MainWindow::addCD()
{
    // Get values
    QString composer = m_composerEdit->text();
    QString albumName = m_albumEdit->text();
    double replacementValue = m_replacementCostSpinBox->value();
    int rating = m_ratingSpinBox->value();

    // Reset GUI
    m_composerEdit->clear();
    m_albumEdit->clear();
    m_replacementCostSpinBox->setValue(0.00);
    m_ratingSpinBox->setValue(0);
    m_composerEdit->setFocus();
    m_addButton->setEnabled(false);

    // Add to model
    m_model->addCD(composer, albumName, replacementValue, rating);

    m_deleteButton->setEnabled(true);
}

void MainWindow::enableButton()
{
    if (m_composerEdit->text().size() != 0 && m_albumEdit->text().size() != 0)
        m_addButton->setEnabled(true);
}

void MainWindow::deleteCD()
{
    QModelIndex index = m_tableView->currentIndex();
    if (!index.isValid())
        return;
    if (QMessageBox::Yes == QMessageBox::warning(this, "Delete row", "Are you sure?", QMessageBox::Yes | QMessageBox::No))
    {
        int row = index.row();
        m_model->removeRow(row);
    }
    if (m_model->rowCount(index) == 0)
        m_deleteButton->setEnabled(false);
}

void MainWindow::setupGui()
{
    setWindowTitle("Music");

    QLabel* composerLabel{new QLabel("Composer")};
    QLabel* albumLabel{new QLabel("Album Title")};
    QLabel* replacementValueLabel{new QLabel("Replacement Cost (R)")};
    QLabel* ratingLabel{new QLabel("Rating")};

    QGridLayout* layout{new QGridLayout(this)};
    layout->addWidget(composerLabel, 0, 0);
    layout->addWidget(albumLabel, 0, 1);
    layout->addWidget(replacementValueLabel, 0, 2);
    layout->addWidget(ratingLabel, 0, 3);
    layout->addWidget(m_composerEdit, 1, 0);
    layout->addWidget(m_albumEdit, 1, 1);
    layout->addWidget(m_replacementCostSpinBox, 1, 2);
    layout->addWidget(m_ratingSpinBox, 1, 3);
    layout->addWidget(m_addButton, 1, 4);
    layout->addWidget(m_tableView, 2, 0, 1, 5);
    layout->addWidget(m_deleteButton, 3, 0, 1, 5);

    m_replacementCostSpinBox->setMinimum(0.00);
    m_replacementCostSpinBox->setMaximum(99000.00);
    m_replacementCostSpinBox->setDecimals(2);
    m_ratingSpinBox->setMinimum(0);
    m_ratingSpinBox->setMaximum(100);

    m_tableView->horizontalHeader()->setStretchLastSection(true);

    m_tableView->setSortingEnabled(true);

    m_addButton->setEnabled(false);
    m_deleteButton->setEnabled(false);

    this->setLayout(layout);
    this->adjustSize();
}
