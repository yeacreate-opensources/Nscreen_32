/********************************************************************************
** Form generated from reading UI file 'LVGLFontDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LVGLFONTDIALOG_H
#define UI_LVGLFONTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_LVGLFontDialog
{
public:
    QGridLayout *gridLayout;
    QToolButton *button_select;
    QDialogButtonBox *buttonBox;
    QLineEdit *edit_name;
    QListWidget *list_font;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *spin_size;
    QLabel *label_2;
    QComboBox *comboBox;
    QLineEdit *preview;

    void setupUi(QDialog *LVGLFontDialog)
    {
        if (LVGLFontDialog->objectName().isEmpty())
            LVGLFontDialog->setObjectName(QStringLiteral("LVGLFontDialog"));
        LVGLFontDialog->resize(577, 392);
        gridLayout = new QGridLayout(LVGLFontDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        button_select = new QToolButton(LVGLFontDialog);
        button_select->setObjectName(QStringLiteral("button_select"));

        gridLayout->addWidget(button_select, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(LVGLFontDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 2);

        edit_name = new QLineEdit(LVGLFontDialog);
        edit_name->setObjectName(QStringLiteral("edit_name"));

        gridLayout->addWidget(edit_name, 0, 0, 1, 1);

        list_font = new QListWidget(LVGLFontDialog);
        list_font->setObjectName(QStringLiteral("list_font"));

        gridLayout->addWidget(list_font, 1, 0, 1, 2);

        groupBox = new QGroupBox(LVGLFontDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        spin_size = new QSpinBox(groupBox);
        spin_size->setObjectName(QStringLiteral("spin_size"));
        spin_size->setMaximum(255);
        spin_size->setValue(12);

        formLayout->setWidget(1, QFormLayout::FieldRole, spin_size);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(100, 0));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox);

        preview = new QLineEdit(groupBox);
        preview->setObjectName(QStringLiteral("preview"));
        preview->setEnabled(false);
        preview->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::SpanningRole, preview);


        gridLayout->addWidget(groupBox, 0, 2, 2, 1);


        retranslateUi(LVGLFontDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LVGLFontDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LVGLFontDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LVGLFontDialog);
    } // setupUi

    void retranslateUi(QDialog *LVGLFontDialog)
    {
        LVGLFontDialog->setWindowTitle(QApplication::translate("LVGLFontDialog", "Import Font", Q_NULLPTR));
        button_select->setText(QApplication::translate("LVGLFontDialog", "...", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("LVGLFontDialog", "Settings", Q_NULLPTR));
        label->setText(QApplication::translate("LVGLFontDialog", "Size:", Q_NULLPTR));
        label_2->setText(QApplication::translate("LVGLFontDialog", "Bpp:", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("LVGLFontDialog", "4 bit-per-pixel", Q_NULLPTR)
         << QApplication::translate("LVGLFontDialog", "2 bit-per-pixel", Q_NULLPTR)
         << QApplication::translate("LVGLFontDialog", "1 bit-per-pixel", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class LVGLFontDialog: public Ui_LVGLFontDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LVGLFONTDIALOG_H
