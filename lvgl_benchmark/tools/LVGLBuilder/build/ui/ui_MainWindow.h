/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LVGLSimulator.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_new;
    QAction *action_load;
    QAction *actionWidget_Box;
    QAction *actionObject_Inspector;
    QAction *actionProperty_Editor;
    QAction *action_save;
    QAction *action_run;
    QAction *action_export_c;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *GUIEditorTab;
    QGridLayout *gridLayout_2;
    LVGLSimulator *simulation;
    QMenuBar *menubar;
    QMenu *menuLittlevGL_Builder;
    QMenu *menu_resent_filess;
    QMenu *menuExport;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuHelp;
    QMenu *menuHelp_2;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QDockWidget *ObjecInspector;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_3;
    QTreeView *object_tree;
    QDockWidget *PropertyEditor;
    QWidget *dockWidgetContents_3;
    QGridLayout *gridLayout_4;
    QTreeView *property_tree;
    QDockWidget *WidgeBox;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout_5;
    QLineEdit *edit_filter;
    QListView *list_widgets;
    QDockWidget *ImageEditor;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *button_add_image;
    QToolButton *button_remove_image;
    QSpacerItem *horizontalSpacer;
    QListWidget *list_images;
    QDockWidget *StyleEditor;
    QWidget *dockWidgetContents_5;
    QVBoxLayout *verticalLayout_3;
    QComboBox *combo_style;
    QTreeView *style_tree;
    QDockWidget *FontEditor;
    QWidget *dockWidgetContents_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *button_add_font;
    QToolButton *button_remove_font;
    QSpacerItem *horizontalSpacer_2;
    QListWidget *list_fonts;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1780, 1165);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/lvgl.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_new = new QAction(MainWindow);
        action_new->setObjectName(QStringLiteral("action_new"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/document.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_new->setIcon(icon1);
        action_load = new QAction(MainWindow);
        action_load->setObjectName(QStringLiteral("action_load"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_load->setIcon(icon2);
        actionWidget_Box = new QAction(MainWindow);
        actionWidget_Box->setObjectName(QStringLiteral("actionWidget_Box"));
        actionWidget_Box->setCheckable(true);
        actionObject_Inspector = new QAction(MainWindow);
        actionObject_Inspector->setObjectName(QStringLiteral("actionObject_Inspector"));
        actionObject_Inspector->setCheckable(true);
        actionProperty_Editor = new QAction(MainWindow);
        actionProperty_Editor->setObjectName(QStringLiteral("actionProperty_Editor"));
        actionProperty_Editor->setCheckable(true);
        action_save = new QAction(MainWindow);
        action_save->setObjectName(QStringLiteral("action_save"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/disk.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_save->setIcon(icon3);
        action_run = new QAction(MainWindow);
        action_run->setObjectName(QStringLiteral("action_run"));
        action_run->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_run->setIcon(icon4);
        action_export_c = new QAction(MainWindow);
        action_export_c->setObjectName(QStringLiteral("action_export_c"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        GUIEditorTab = new QWidget();
        GUIEditorTab->setObjectName(QStringLiteral("GUIEditorTab"));
        gridLayout_2 = new QGridLayout(GUIEditorTab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        simulation = new LVGLSimulator(GUIEditorTab);
        simulation->setObjectName(QStringLiteral("simulation"));

        gridLayout_2->addWidget(simulation, 0, 0, 1, 1);

        tabWidget->addTab(GUIEditorTab, QString());

        verticalLayout->addWidget(tabWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1780, 21));
        menuLittlevGL_Builder = new QMenu(menubar);
        menuLittlevGL_Builder->setObjectName(QStringLiteral("menuLittlevGL_Builder"));
        menu_resent_filess = new QMenu(menuLittlevGL_Builder);
        menu_resent_filess->setObjectName(QStringLiteral("menu_resent_filess"));
        menuExport = new QMenu(menuLittlevGL_Builder);
        menuExport->setObjectName(QStringLiteral("menuExport"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuHelp_2 = new QMenu(menubar);
        menuHelp_2->setObjectName(QStringLiteral("menuHelp_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        ObjecInspector = new QDockWidget(MainWindow);
        ObjecInspector->setObjectName(QStringLiteral("ObjecInspector"));
        ObjecInspector->setBaseSize(QSize(330, 300));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout_3 = new QGridLayout(dockWidgetContents);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        object_tree = new QTreeView(dockWidgetContents);
        object_tree->setObjectName(QStringLiteral("object_tree"));
        object_tree->setExpandsOnDoubleClick(false);

        gridLayout_3->addWidget(object_tree, 0, 0, 1, 1);

        ObjecInspector->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), ObjecInspector);
        PropertyEditor = new QDockWidget(MainWindow);
        PropertyEditor->setObjectName(QStringLiteral("PropertyEditor"));
        PropertyEditor->setBaseSize(QSize(330, 300));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        gridLayout_4 = new QGridLayout(dockWidgetContents_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        property_tree = new QTreeView(dockWidgetContents_3);
        property_tree->setObjectName(QStringLiteral("property_tree"));
        property_tree->setMinimumSize(QSize(400, 0));
        property_tree->setAlternatingRowColors(true);

        gridLayout_4->addWidget(property_tree, 0, 0, 1, 1);

        PropertyEditor->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), PropertyEditor);
        WidgeBox = new QDockWidget(MainWindow);
        WidgeBox->setObjectName(QStringLiteral("WidgeBox"));
        WidgeBox->setBaseSize(QSize(330, 0));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        gridLayout_5 = new QGridLayout(dockWidgetContents_2);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        edit_filter = new QLineEdit(dockWidgetContents_2);
        edit_filter->setObjectName(QStringLiteral("edit_filter"));
        edit_filter->setAutoFillBackground(false);
        edit_filter->setInputMethodHints(Qt::ImhNone);

        gridLayout_5->addWidget(edit_filter, 0, 0, 1, 1);

        list_widgets = new QListView(dockWidgetContents_2);
        list_widgets->setObjectName(QStringLiteral("list_widgets"));
        QFont font;
        font.setPointSize(12);
        list_widgets->setFont(font);
        list_widgets->setDragEnabled(true);
        list_widgets->setDragDropMode(QAbstractItemView::DragOnly);

        gridLayout_5->addWidget(list_widgets, 1, 0, 1, 1);

        WidgeBox->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), WidgeBox);
        ImageEditor = new QDockWidget(MainWindow);
        ImageEditor->setObjectName(QStringLiteral("ImageEditor"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        button_add_image = new QToolButton(dockWidgetContents_4);
        button_add_image->setObjectName(QStringLiteral("button_add_image"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_add_image->setIcon(icon5);
        button_add_image->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(button_add_image);

        button_remove_image = new QToolButton(dockWidgetContents_4);
        button_remove_image->setObjectName(QStringLiteral("button_remove_image"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_remove_image->setIcon(icon6);
        button_remove_image->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(button_remove_image);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        list_images = new QListWidget(dockWidgetContents_4);
        list_images->setObjectName(QStringLiteral("list_images"));
        list_images->setContextMenuPolicy(Qt::CustomContextMenu);
        list_images->setIconSize(QSize(256, 256));
        list_images->setViewMode(QListView::IconMode);

        verticalLayout_2->addWidget(list_images);

        ImageEditor->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), ImageEditor);
        StyleEditor = new QDockWidget(MainWindow);
        StyleEditor->setObjectName(QStringLiteral("StyleEditor"));
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QStringLiteral("dockWidgetContents_5"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        combo_style = new QComboBox(dockWidgetContents_5);
        combo_style->setObjectName(QStringLiteral("combo_style"));

        verticalLayout_3->addWidget(combo_style);

        style_tree = new QTreeView(dockWidgetContents_5);
        style_tree->setObjectName(QStringLiteral("style_tree"));

        verticalLayout_3->addWidget(style_tree);

        StyleEditor->setWidget(dockWidgetContents_5);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), StyleEditor);
        FontEditor = new QDockWidget(MainWindow);
        FontEditor->setObjectName(QStringLiteral("FontEditor"));
        dockWidgetContents_6 = new QWidget();
        dockWidgetContents_6->setObjectName(QStringLiteral("dockWidgetContents_6"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents_6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        button_add_font = new QToolButton(dockWidgetContents_6);
        button_add_font->setObjectName(QStringLiteral("button_add_font"));
        button_add_font->setIcon(icon5);
        button_add_font->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(button_add_font);

        button_remove_font = new QToolButton(dockWidgetContents_6);
        button_remove_font->setObjectName(QStringLiteral("button_remove_font"));
        button_remove_font->setIcon(icon6);
        button_remove_font->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(button_remove_font);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        list_fonts = new QListWidget(dockWidgetContents_6);
        list_fonts->setObjectName(QStringLiteral("list_fonts"));
        list_fonts->setContextMenuPolicy(Qt::CustomContextMenu);

        verticalLayout_4->addWidget(list_fonts);

        FontEditor->setWidget(dockWidgetContents_6);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), FontEditor);

        menubar->addAction(menuLittlevGL_Builder->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menuHelp_2->menuAction());
        menuLittlevGL_Builder->addAction(action_new);
        menuLittlevGL_Builder->addAction(action_load);
        menuLittlevGL_Builder->addAction(action_save);
        menuLittlevGL_Builder->addSeparator();
        menuLittlevGL_Builder->addAction(menuExport->menuAction());
        menuLittlevGL_Builder->addSeparator();
        menuLittlevGL_Builder->addAction(menu_resent_filess->menuAction());
        menuExport->addAction(action_export_c);
        menuView->addSeparator();
        toolBar->addAction(action_new);
        toolBar->addAction(action_load);
        toolBar->addAction(action_save);
        toolBar->addSeparator();
        toolBar->addAction(action_run);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "LVGL Builder", Q_NULLPTR));
        action_new->setText(QApplication::translate("MainWindow", "New", Q_NULLPTR));
        action_load->setText(QApplication::translate("MainWindow", "Load...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_load->setToolTip(QApplication::translate("MainWindow", "Load file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionWidget_Box->setText(QApplication::translate("MainWindow", "Widget Box", Q_NULLPTR));
        actionObject_Inspector->setText(QApplication::translate("MainWindow", "Object Inspector", Q_NULLPTR));
        actionProperty_Editor->setText(QApplication::translate("MainWindow", "Property Editor", Q_NULLPTR));
        action_save->setText(QApplication::translate("MainWindow", "Save ...", Q_NULLPTR));
        action_run->setText(QApplication::translate("MainWindow", "Run ...", Q_NULLPTR));
        action_export_c->setText(QApplication::translate("MainWindow", "C Project ...", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(GUIEditorTab), QApplication::translate("MainWindow", "GUI Editor", Q_NULLPTR));
        menuLittlevGL_Builder->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menu_resent_filess->setTitle(QApplication::translate("MainWindow", "Recent files", Q_NULLPTR));
        menuExport->setTitle(QApplication::translate("MainWindow", "Export", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        menuHelp_2->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        ObjecInspector->setWindowTitle(QApplication::translate("MainWindow", "Object Inspector", Q_NULLPTR));
        PropertyEditor->setWindowTitle(QApplication::translate("MainWindow", "Property Editor", Q_NULLPTR));
        WidgeBox->setWindowTitle(QApplication::translate("MainWindow", "Widget Box", Q_NULLPTR));
        edit_filter->setPlaceholderText(QApplication::translate("MainWindow", "Filter", Q_NULLPTR));
        ImageEditor->setWindowTitle(QApplication::translate("MainWindow", "Image Editor", Q_NULLPTR));
        button_add_image->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        button_remove_image->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        StyleEditor->setWindowTitle(QApplication::translate("MainWindow", "Style Editor", Q_NULLPTR));
        FontEditor->setWindowTitle(QApplication::translate("MainWindow", "Font Editor", Q_NULLPTR));
        button_add_font->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        button_remove_font->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
