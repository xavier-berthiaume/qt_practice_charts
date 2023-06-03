#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets/QMainWindow>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QBarSet *set0 = new QBarSet("Altuve");
    QBarSet *set1 = new QBarSet("Martinez");
    QBarSet *set2 = new QBarSet("Segura");
    QBarSet *set3 = new QBarSet("Simmons");
    QBarSet *set4 = new QBarSet("Trout");

    *set0 << 283 << 341 << 313 << 338 << 346 << 335;
    *set1 << 250 << 315 << 282 << 307 << 303 << 330;
    *set2 << 294 << 246 << 257 << 319 << 300 << 325;
    *set3 << 248 << 244 << 265 << 281 << 278 << 313;
    *set4 << 323 << 287 << 299 << 315 << 306 << 313;

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Batting average by year");
    chart->setAnimationOptions(QChart::AllAnimations);

    QStringList categories;
    categories << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";
    QBarCategoryAxis *axis = QBarCategoryAxis();
    axis->append(categories);

    chart->createDefaultAxes();
    chart->setAxis(axis, series);
    chart->legend()->setVisible(true);
    chart->legned()->setAlignment(Qt::AlignLeft);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
