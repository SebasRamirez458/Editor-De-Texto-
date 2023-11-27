#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox.h> // Para mostrar mensajes
#include <QFileDialog> // Para abrir archivos
#include <QTextStream> // Para leer archivos
#include <QFile> // Para abrir archivos
#include <QPrinter> // Para imprimir
#include <QPrintDialog> // Para imprimir
#include <QTextBlockFormat> // Para alinear texto
#include <QTextCursor> // Para alinear texto
#include <QColorDialog> // Para cambiar color de fuente


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString ruta;

//NEGRITA
void MainWindow::on_Negrita_clicked()
{
    QTextCharFormat format = ui->textEdit->currentCharFormat();
    format.fontWeight() == QFont::Normal? format.setFontWeight(QFont::Bold) : format.setFontWeight(QFont::Normal );
    ui->textEdit->mergeCurrentCharFormat(format);
    ui->textEdit->setFocus();
}

//CURSIVA
void MainWindow::on_Cursiva_clicked()
{
    QTextCharFormat format = ui->textEdit->currentCharFormat();
    format.setFontItalic(!format.fontItalic());
    ui->textEdit->mergeCurrentCharFormat(format);
    ui->textEdit->setFocus();
}

//SUBRAYADO
void MainWindow::on_Subrrayada_clicked()
{
    QTextCharFormat format = ui->textEdit->currentCharFormat();
    format.setFontUnderline(!format.fontUnderline());
    ui->textEdit->mergeCurrentCharFormat(format);
    ui->textEdit->setFocus();
}

//TACHADO
void MainWindow::on_Tachado_clicked()
{
    QTextCharFormat format = ui->textEdit->currentCharFormat();
    format.setFontStrikeOut(!format.fontStrikeOut());
    ui->textEdit->mergeCurrentCharFormat(format);
    ui->textEdit->setFocus();
}


//TAMAÑO
void MainWindow::on_Size_valueChanged(int arg1)
{
    QTextCharFormat format = ui->textEdit->currentCharFormat();
    format.setFontPointSize(arg1);
    ui->textEdit->mergeCurrentCharFormat(format);
}

//Alineación Centrada
void MainWindow::on_Centro_clicked()
{
    QTextCursor cursor = ui->textEdit->textCursor(); // Obtiene el cursor del QTextEdit
    QTextBlockFormat blockFormat;
    blockFormat.setAlignment(Qt::AlignCenter); // Alinea el bloque de texto al centro
    cursor.mergeBlockFormat(blockFormat); // Aplica el formato del bloque de texto a la selección
    ui->textEdit->setTextCursor(cursor); // Establece el cursor en el QTextEdit
    ui->textEdit->setFocus();
}

//Alineación izquierda
void MainWindow::on_Izquierda_clicked()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextBlockFormat blockFormat;
    blockFormat.setAlignment(Qt::AlignLeft); // Alinea el bloque de texto a la izquierda
    cursor.mergeBlockFormat(blockFormat); // Aplica el formato del bloque de texto a la selección
    ui->textEdit->setTextCursor(cursor); // Establece el cursor en el QTextEdit
    ui->textEdit->setFocus();
}

//Alineación derecha
void MainWindow::on_Derecha_clicked()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextBlockFormat blockFormat;
    blockFormat.setAlignment(Qt::AlignRight); // Alinea el bloque de texto a la derecha
    cursor.mergeBlockFormat(blockFormat); // Aplica el formato del bloque de texto a la selección
    ui->textEdit->setTextCursor(cursor); // Establece el cursor en el QTextEdit
    ui->textEdit->setFocus();
}

//Cambiar fuente
void MainWindow::on_fontComboBox_currentFontChanged(const QFont &f)
{
    QTextCharFormat format = ui->textEdit->currentCharFormat();
    QFont font = f;
    qreal Size = format.fontPointSize();
    font.setPointSize(Size);
    format.setFont(font);
    ui->textEdit->mergeCurrentCharFormat(format);
    ui->textEdit->setFocus();
}

//Abrir archivo
void MainWindow::on_actionAbrir_triggered() // Abrir archivo
{
    QString fileName = QFileDialog::getOpenFileName(this, "Abrir", "", "Archivos de Texto (*.txt);;Open Document (*.odt);;Archivos HTML (*.html)");
    QFile file(fileName); 
    QFileInfo fileInfo(ruta);
    ruta = fileName;
    if (!file.open(QIODevice::ReadWrite | QFile::Text)) {
        QMessageBox::warning(this, "Advertencia", "No se puede abrir el archivo: ");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
    ui->archivo->setText(ruta);
}



void MainWindow::on_actionGuardar_triggered() // Guardar archivo
{
    QFile file(ruta);
    QFileInfo fileInfo(ruta);
    QString extension = fileInfo.suffix();

    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Advertencia", "No se puede guardar el archivo: ");
        return;
    }
    QTextStream stream(&file);

    if (extension == "pdf") {
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(ruta);
        ui->textEdit->document()->print(&printer);
    }
    else if (extension == "html") {
        stream << ui->textEdit->toHtml();
    }
    else if (extension == "txt") {
        stream << ui->textEdit->toPlainText();
    }
    else if (extension == "odt") {
        stream << ui->textEdit->toHtml();
    }
    else {
        ui->archivo->setText("No se puede guardar el archivo");
        file.close(); 
        return;
    }

    file.close();
    ui->archivo->setText(ruta);
}


void MainWindow::on_actionEliminar_triggered() //eliminar archivo
{
    QFile file(ruta);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Advertencia", "No se puede eliminar el archivo: ");
        return;
    }
    file.remove();
    
}


void MainWindow::on_actionCerrar_triggered() //cerrar ventana
{
    close();
}


void MainWindow::on_actionImprimir_triggered()
{
    QPrinter printer;
    printer.setPrinterName("");
    QPrintDialog dialog(&printer, this);
    if (dialog.exec() == QDialog::Rejected) return;
    ui->textEdit->print(&printer);
}


void MainWindow::on_ArchivoPDF_triggered()
{
    //GUARDAR COMO PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Exportar PDF", "", "*.pdf");
    ruta = fileName;
    QFile file(fileName);
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    ui->textEdit->document()->print(&printer);

}


void MainWindow::on_ArchivoHTML_triggered()
{
    //GUARDAR COMO HTML
    QString fileName = QFileDialog::getSaveFileName(this, "Exportar HTML", "", "*.html");
    ruta = fileName;
    QFile file(fileName);
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".html"); }
    QTextStream stream(&file);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) { return; }
    stream << ui->textEdit->toHtml();
    file.close();
}

void MainWindow::on_ArchivoTXT_triggered()
{
    //GUARDAR COMO TXT
    QString fileName = QFileDialog::getSaveFileName(this, "Exportar TXT", "", "*.txt");
    ruta = fileName;
    QFile file(fileName);
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".txt"); }
    QTextStream stream(&file);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) { return; }
    stream << ui->textEdit->toPlainText();
    file.close();
}


void MainWindow::on_ArchivoODT_triggered()
{
    //GUARDAR CON FORMATO EN ODT
    QString fileName = QFileDialog::getSaveFileName(this, "Exportar ODT", "", "*.odt");
    ruta = fileName;
    QFile file(fileName);
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".odt"); }
    QTextStream stream(&file);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) { return; }
    stream << ui->textEdit->toHtml(); 
    file.close();
}


void MainWindow::on_CambiarColor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Color de fuente");
    if (color.isValid()) {
        QTextCharFormat format = ui->textEdit->currentCharFormat();
        format.setForeground(color);
        ui->textEdit->mergeCurrentCharFormat(format);
        ui->textEdit->setFocus();
    }
}


void MainWindow::on_ColorDeFondo_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Color de fondo");
    if (color.isValid()) {
        QTextCharFormat format = ui->textEdit->currentCharFormat();
        format.setBackground(color);
        ui->textEdit->mergeCurrentCharFormat(format);
        ui->textEdit->setFocus();
    }

}

