#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Negrita_clicked();

    void on_Cursiva_clicked();

    void on_Subrrayada_clicked();

    void on_Size_valueChanged(int arg1);

    void on_Centro_clicked();

    void on_Izquierda_clicked();

    void on_Derecha_clicked();

    void on_Tachado_clicked();

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_actionAbrir_triggered();

    void on_actionGuardar_triggered();

    void on_actionEliminar_triggered();

    void on_actionCerrar_triggered();

    void on_actionImprimir_triggered();

    void on_ArchivoPDF_triggered();

    void on_ArchivoHTML_triggered();

    void on_ArchivoTXT_triggered();

    void on_ArchivoODT_triggered();

    void on_CambiarColor_clicked();

    void on_ColorDeFondo_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
