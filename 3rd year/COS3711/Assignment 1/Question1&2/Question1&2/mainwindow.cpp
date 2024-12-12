#include "mainwindow.h"
#include <QVBoxLayout>
#include <QDateEdit>
#include <QMetaObject>
#include <QMetaProperty>

MainWindow::MainWindow(QWidget *parent)
    : QWidget{parent}
{
    titleLabel = new QLabel("Fill in the data and click Add");

    softwareNameLabel = new QLabel("Software Name:", this);
    softwareNameLineEdit = new QLineEdit(this);

    reviewDateLabel = new QLabel("Review Date:", this);
    reviewDateEdit = new QDateEdit(QDate::currentDate(), this); // Set default date to current date

    recommendationLabel = new QLabel("Recommendation:", this);
    recommendationCheckBox = new QCheckBox(this);

    addReviewButton = new QPushButton("Add Review", this);
    displayReviewsButton = new QPushButton("Display Reviews", this);
    displayReviewDetailsButton = new QPushButton("Display Review Details", this); // New button

    // Set up layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addWidget(softwareNameLabel);
    layout->addWidget(softwareNameLineEdit);
    layout->addWidget(reviewDateLabel);
    layout->addWidget(reviewDateEdit);
    layout->addWidget(recommendationLabel);
    layout->addWidget(recommendationCheckBox);
    layout->addWidget(addReviewButton);
    layout->addWidget(displayReviewsButton);
    layout->addWidget(displayReviewDetailsButton);


    // Connect the "Add Review" button's clicked() signal to the addReview() slot
    connect(addReviewButton, &QPushButton::clicked, this, &MainWindow::addReview);

    // Connect the "Display Reviews" button's clicked() signal to the displayReviews() slot
    connect(displayReviewsButton, &QPushButton::clicked, this, &MainWindow::displayReviews);

    // Connect the "Display Review Details" button's clicked() signal to the displayReviewDetails() slot
    connect(displayReviewDetailsButton, &QPushButton::clicked, this, &MainWindow::displayReviewDetails);
}

QString MainWindow::getSoftwareName() const
{
    return softwareNameLineEdit->text();
}

QDate MainWindow::getReviewDate() const
{
    return reviewDateEdit->date();
}

bool MainWindow::isRecommended() const
{
    return recommendationCheckBox->isChecked();
}

MainWindow::~MainWindow()
{
    // Clean up allocated resources
    delete softwareNameLabel;
    delete softwareNameLineEdit;
    delete reviewDateLabel;
    delete reviewDateEdit;
    delete recommendationLabel;
    delete recommendationCheckBox;
    delete addReviewButton;
    delete displayReviewsButton;
}

// Slot to handle adding a review
void MainWindow::addReview()
{
    // Retrieve the data from the GUI components
    QString softwareName = getSoftwareName();
    QDate reviewDate = getReviewDate();
    bool recommended = isRecommended();

    // Create a new ReviewData instance with the retrieved data
    ReviewData newReview(softwareName, reviewDate, recommended);

    // Store the new review in the container
    reviewDataList.append(newReview);
}


// Slot to handle displaying all reviews
void MainWindow::displayReviews()
{

    qDebug() << "----------------------------------------------";
    qDebug() << "Software Name    |  Review Date  | Recommended";
    qDebug() << "----------------------------------------------";


    for (const ReviewData &review : reviewDataList) {
        qDebug() << QString("%1 | %2 | %3")
                        .arg(review.softwareName(), -18)
                        .arg(review.reviewDate().toString("yyyy-MM-dd"), -14)
                        .arg(review.isRecommended() ? "Yes" : "No");
    }
}

void MainWindow::displayReviewDetails()
{
    if (reviewDataList.isEmpty()) {
        qDebug() << "No reviews available.";
        return;
    }

    // Get the meta object of ReviewData class
    const QMetaObject *metaObject = &staticMetaObject;

    // Print header
    qDebug() << "----------------------------------------------";
    qDebug() << "Review Details:";
    qDebug() << "----------------------------------------------";


    for (const ReviewData &review : reviewDataList) {
        qDebug() << "Review:";
        // Loop through properties using reflective programming
        for (int i = metaObject->propertyOffset(); i < metaObject->propertyCount(); ++i) {
            QMetaProperty property = metaObject->property(i);
            QVariant value = property.readOnGadget(&review); // Read property value as QVariant
            qDebug() << QString("%1: %2").arg(property.name(), -15).arg(value.toString());
        }
    }
}

