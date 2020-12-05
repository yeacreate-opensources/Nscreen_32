/********************************************************************************
** Form generated from reading UI file 'LVGLNewDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LVGLNEWDIALOG_H
#define UI_LVGLNEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LVGLNewDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *radio_landscape;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_5;
    QRadioButton *radio_portrait;
    QSpinBox *spin_height;
    QSpinBox *spin_width;
    QComboBox *combo_resolution;
    QLineEdit *edit_name;
    QLabel *label_6;
    QDialogButtonBox *buttonBox;
    QButtonGroup *group_oriantation;

    void setupUi(QDialog *LVGLNewDialog)
    {
        if (LVGLNewDialog->objectName().isEmpty())
            LVGLNewDialog->setObjectName(QStringLiteral("LVGLNewDialog"));
        LVGLNewDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(LVGLNewDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(LVGLNewDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radio_landscape = new QRadioButton(groupBox);
        group_oriantation = new QButtonGroup(LVGLNewDialog);
        group_oriantation->setObjectName(QStringLiteral("group_oriantation"));
        group_oriantation->addButton(radio_landscape);
        radio_landscape->setObjectName(QStringLiteral("radio_landscape"));
        radio_landscape->setChecked(true);

        gridLayout->addWidget(radio_landscape, 4, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/icons/Landscape.png")));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 6, 1, 1, 1);

        radio_portrait = new QRadioButton(groupBox);
        group_oriantation->addButton(radio_portrait);
        radio_portrait->setObjectName(QStringLiteral("radio_portrait"));

        gridLayout->addWidget(radio_portrait, 4, 2, 1, 1);

        spin_height = new QSpinBox(groupBox);
        spin_height->setObjectName(QStringLiteral("spin_height"));
        spin_height->setMinimum(1);
        spin_height->setMaximum(32767);

        gridLayout->addWidget(spin_height, 3, 1, 1, 2);

        spin_width = new QSpinBox(groupBox);
        spin_width->setObjectName(QStringLiteral("spin_width"));
        spin_width->setMinimum(1);
        spin_width->setMaximum(32767);

        gridLayout->addWidget(spin_width, 2, 1, 1, 2);

        combo_resolution = new QComboBox(groupBox);
        combo_resolution->setObjectName(QStringLiteral("combo_resolution"));

        gridLayout->addWidget(combo_resolution, 1, 1, 1, 2);

        edit_name = new QLineEdit(groupBox);
        edit_name->setObjectName(QStringLiteral("edit_name"));

        gridLayout->addWidget(edit_name, 0, 1, 1, 2);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/icons/Portrait.png")));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 6, 2, 1, 1);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(LVGLNewDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(LVGLNewDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LVGLNewDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LVGLNewDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LVGLNewDialog);
    } // setupUi

    void retranslateUi(QDialog *LVGLNewDialog)
    {
        LVGLNewDialog->setWindowTitle(QApplication::translate("LVGLNewDialog", "New project", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("LVGLNewDialog", "Project", Q_NULLPTR));
        radio_landscape->setText(QApplication::translate("LVGLNewDialog", "Landscape", Q_NULLPTR));
        label_2->setText(QApplication::translate("LVGLNewDialog", "Resolution:", Q_NULLPTR));
        label_3->setText(QApplication::translate("LVGLNewDialog", "Width:", Q_NULLPTR));
        label_4->setText(QApplication::translate("LVGLNewDialog", "Height", Q_NULLPTR));
        label->setText(QApplication::translate("LVGLNewDialog", "Name:", Q_NULLPTR));
        label_5->setText(QString());
        radio_portrait->setText(QApplication::translate("LVGLNewDialog", "Portrait", Q_NULLPTR));
        combo_resolution->clear();
        combo_resolution->insertItems(0, QStringList()
         << QApplication::translate("LVGLNewDialog", "Custom", Q_NULLPTR)
        );
        edit_name->setText(QApplication::translate("LVGLNewDialog", "App", Q_NULLPTR));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LVGLNewDialog: public Ui_LVGLNewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LVGLNEWDIALOG_H
