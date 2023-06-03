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

QChartView *createBarChart();
QChartView *createStackedBarChart();
QChartView *createLineChart();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QChartView *chartView = createLineChart();

    MainWindow w;

    // Make the created chart a widget that will be displayed
    w.setCentralWidget(chartView);
    w.resize(500, 400);

    w.show();

    return a.exec();
}

QChartView *createBarChart() {
    // Assign names to the set of bars
    QBarSet *set0 = new QBarSet("Altuve");
    QBarSet *set1 = new QBarSet("Martinez");
    QBarSet *set2 = new QBarSet("Segura");
    QBarSet *set3 = new QBarSet("Simmons");
    QBarSet *set4 = new QBarSet("Trout");

    // Assign values for each bar to be displayed
    *set0 << 283 << 341 << 313 << 338 << 346 << 335;
    *set1 << 250 << 315 << 282 << 307 << 303 << 330;
    *set2 << 294 << 246 << 257 << 319 << 300 << 325;
    *set3 << 248 << 244 << 265 << 281 << 278 << 313;
    *set4 << 323 << 287 << 299 << 315 << 306 << 313;

    // Add all sets of data to the chart
    QBarSeries *series = new QBarSeries();

    // Stack the bar chart
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    // Define the bar chart to display
    QChart *chart = new QChart();
    // Add the data to the chart
    chart->addSeries(series);

    // Set the title name
    chart->setTitle("Batting average by year");

    // Set the opening animation
    // Options are NoAnimation, GridAxisAnimation, SeriesAnimations
    chart->setAnimationOptions(QChart::AllAnimations);

    // Create the category names
    QStringList categories;
    categories << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";

    // Add the category names to an axis
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();

    // For a Bar Chart
    // chart->setAxisX(axis, series); DEPRECATED FUNCTION, USE BELOW
    chart->addAxis(axis, Qt::AlignBottom);

    // Define where the legend is displayed
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Display the chart
    QChartView *chartView = new QChartView(chart);
    chartView ->setRenderHint(QPainter::Antialiasing);

    // Change the display color palette
    QPalette palette = qApp->palette();
    palette.setColor(QPalette::Window, QRgb(0x111111));
    palette.setColor(QPalette::WindowText, QRgb(0x404040));
    qApp->setPalette(palette);

    return chartView;
}

QChartView *createStackedBarChart() {
    // Assign names to the set of bars
    QBarSet *set0 = new QBarSet("Altuve");
    QBarSet *set1 = new QBarSet("Martinez");
    QBarSet *set2 = new QBarSet("Segura");
    QBarSet *set3 = new QBarSet("Simmons");
    QBarSet *set4 = new QBarSet("Trout");

    // Assign values for each bar to be displayed
    *set0 << 283 << 341 << 313 << 338 << 346 << 335;
    *set1 << 250 << 315 << 282 << 307 << 303 << 330;
    *set2 << 294 << 246 << 257 << 319 << 300 << 325;
    *set3 << 248 << 244 << 265 << 281 << 278 << 313;
    *set4 << 323 << 287 << 299 << 315 << 306 << 313;

    // Add all sets of data to the chart
    QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();

    // Stack the bar chart
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    // Define the bar chart to display
    QChart *chart = new QChart();
    // Add the data to the chart
    chart->addSeries(series);

    // Set the title name
    chart->setTitle("Batting average by year");

    // Set the opening animation
    // Options are NoAnimation, GridAxisAnimation, SeriesAnimations
    chart->setAnimationOptions(QChart::AllAnimations);

    // Create the category names
    QStringList categories;
    categories << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";

    // Add the category names to an axis
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();

    // For a Bar Chart
    // chart->setAxisX(axis, series); DEPRECATED FUNCTION, USE BELOW
    chart->addAxis(axis, Qt::AlignLeft);

    // Define where the legend is displayed
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Display the chart
    QChartView *chartView = new QChartView(chart);
    chartView ->setRenderHint(QPainter::Antialiasing);

    // Change the display color palette
    QPalette palette = qApp->palette();
    palette.setColor(QPalette::Window, QRgb(0xffffff));
    palette.setColor(QPalette::WindowText, QRgb(0x404040));
    qApp->setPalette(palette);

    return chartView;
}

QChartView *createLineChart() {
    QLineSeries *series = new QLineSeries();
    series->append(0, 16);
    series->append(1, 25);
    series->append(2, 24);
    series->append(3, 19);
    series->append(4, 33);
    series->append(5, 25);
    series->append(6, 34);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();

    QFont font;
    font.setPixelSize(18);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::black));
    chart->setTitle("Barry Bonds Home Runs with Pittsburgh Pirates");

    QPen pen(QRgb(0x000000));
    pen.setWidth(5);
    series->setPen(pen);

    chart->setAnimationOptions(QChart::SeriesAnimations);

    QCategoryAxis *axisX = new QCategoryAxis();
    axisX->append("1986", 0);
    axisX->append("1987", 1);
    axisX->append("1988", 2);
    axisX->append("1989", 3);
    axisX->append("1990", 4);
    axisX->append("1991", 5);
    axisX->append("1992", 6);

    QChartView *chart_view = new QChartView(chart);
    chart_view->setRenderHint(QPainter::Antialiasing, true);

    return chart_view;
}
