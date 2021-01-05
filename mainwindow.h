#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTcpSocket>
#include <QDataStream>
//#include <QNetworkSession>
#include <QDialog>
#include <QMessageBox>
#include <qwt_plot.h>
//#include <QSerialPort>
//#include <QSerialPortInfo>
#include "ddecomm.h"
#include "plot.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = 0);
   ~MainWindow();

public slots:
   void runTimer();
   void updateDigitDisplay();

   void AzDT();
   void AzDH();
   void AzDO();
   void AzDD();
   void AzUT();
   void AzUH();
   void AzUO();
   void AzUD();
   void ElDT();
   void ElDH();
   void ElDO();
   void ElDD();
   void ElUT();
   void ElUH();
   void ElUO();
   void ElUD();


   void parseTCPIncoming();
   void displayError(QAbstractSocket::SocketError socketError);
   void TCPconnected();
   void TCPdisconnected();

   void toggleTCPConnection();
   void sendOnce();
   void ESTOP();
   void toggleActiveTracking();
   void toggleDDEConnection();   

   void EL2CMD();
   void AZ2CMD();

private:
   Ui::MainWindow *ui;

   //Methods

   //Initialization Methods


   //Stuff
   void parseDDEIncoming();
   void requestRotorPosition();
   void sendRotorPosition();

   //Variables
   //Positions
   float CurrentRotorEl;
   float CurrentRotorAz;
   float CommandedRotorEl;
   float CommandedRotorAz;
   float DDETargetEl=45;
   float DDETargetAz=45;

   //DDE Variables
   QString currentDDETarget;
   DdeComm DDEPort;
   QString DDEAPP;
   QString DDETOPIC;
   QString DDEITEM;
   unsigned long DDEConversation=0;
   bool DDEConnected=false;

   //Network
   QTcpSocket *tcpSocket;
   QString TCPDataIn;
   bool networkConnected=false;

   //Behaviours
   bool ActiveTrack;

   Plot *skyPlotObj; //make this a pointer so we can control when the constructor gets run
};

#endif // MAINWINDOW_H
