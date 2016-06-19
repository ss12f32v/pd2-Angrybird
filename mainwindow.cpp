        #include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,960,540);
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),QSizeF(960,540));
    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32.0,3.0,QPixmap(":/image/GROUND.png").scaled(width(),height()/6.0),world,scene));

    // Create bird (You can edit here)
   //  birdie[0] = new Bird(2.0f,9.0f,0.27,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    // birdie[1]= new Bird(2.0f,10.0f,0.27f,&timer,QPixmap(":/image/bluebird.png").scaled(height()/9.0,height()/9.0),world,scene);

    // Create barrier
        itemList.push_back(new barrier(22.0 ,5.0, 0.1, 2.5, &timer, QPixmap(":/image/verbarrier").scaled(30,120), world, scene));
        itemList.push_back(new barrier(25.0, 5.0, 0.1, 2.5, &timer, QPixmap(":/image/verbarrier").scaled(30, 120), world, scene));
        itemList.push_back(new barrier(28.0, 5.0, 0.1, 2.5, &timer, QPixmap(":/image/verbarrier").scaled(30, 120), world, scene));
    //Create sling
        itemList.push_back(new sling(5.0, 5.0, 2.0, 2.0, QPixmap(":/image/Slingshot").scaled(50, 105), world, scene));
    // Create greenpig
        green[0]=new greenidiot(23.0f,4.0f,0.3f,&timer,QPixmap(":/image/greenidiot.png").scaled(40,40),world,scene);
        green[1]=new greenidiot(26.0f,4.0f,0.3f,&timer,QPixmap(":/image/greenidiot.png").scaled(40,40),world,scene);
        green[2]=new greenidiot(20.0f,4.0f,0.3f,&timer,QPixmap(":/image/greenidiot.png").scaled(40,40),world,scene);
        itemList.push_back(green[0]);
        itemList.push_back(green[1]);
        itemList.push_back(green[2]);

    // Setting the Velocity
    // birdie[0]->setLinearVelocity(b2Vec2(10,0));
    // itemList.push_back(birdie[0]);
    //birdie[1]->setLinearVelocity(b2Vec2(0,0));
    //itemList.push_back(birdie1);

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
    //create exit button
    exitbutton = new QPushButton;
    exitbutton->setText("EXIT");
    exitbutton->setGeometry(200, 10, 80, 50);
    exitbutton->setStyleSheet("color:white; background-color:black; transparent; font: bold 18px;");
    connect(exitbutton, SIGNAL(clicked(bool)), this, SLOT(exit_game()));
    scene->addWidget(exitbutton);
    //create restart button
    restartbutton = new QPushButton;
    restartbutton->setText("RESTART");
    restartbutton->setGeometry(100, 10, 100, 50);
    restartbutton->setStyleSheet("color:white; background-color:black; transparent; font: bold 18px;");
    connect(restartbutton, SIGNAL(clicked(bool)), this, SLOT(restart_game()));
    scene->addWidget(restartbutton);

}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        /* TODO : add your code here */
        //std::cout << "Press !" << std::endl ;
       // QMouseEvent *pressevent = static_cast<QMouseEvent*>(event);
        startx = QCursor::pos().x();
        starty = QCursor::pos().y();

   }

    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        endx = QCursor::pos().x();
        endy = QCursor::pos().y();
        changex=startx-endx;
        changey=starty-endy;

        birdie[i]->setLinearVelocity(b2Vec2(changex*0.3,changey*0.3));


        itemList.push_back(birdie[i]);


    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
    kill();


}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
void MainWindow::keyPressEvent(QKeyEvent * event)
{
 if(event->key() == Qt::Key_A)
 {
     birdie[0] = new Bird(5.0f,9.0f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);

 }
 if(event->key() == Qt::Key_B)
 {
     birdie[1] = new Bird(5.0f,9.0f,0.27f,&timer,QPixmap(":/image/bluebird.png").scaled(height()/9.0,height()/9.0),world,scene);
     i++;
     delete birdie[0];
 }
 if(event->key() == Qt::Key_C)
 {
     birdie[2] = new Bird(5.0f,9.0f,0.27f,&timer,QPixmap(":/image/yellowbird.png").scaled(height()/9.0,height()/9.0),world,scene);
     i++;
     delete birdie[1];
 }
 if(event->key() == Qt::Key_D)
 {
     birdie[3] = new Bird(5.0f,9.0f,0.27f,&timer,QPixmap(":/image/whitebird.png").scaled(height()/9.0,height()/9.0),world,scene);
     i++;
     delete birdie[2];
 }

 }


void MainWindow::kill()
{
    if(green[0]!=NULL)
    {
    green0=green[0]->speed.x;
    if(green0>0)
    {
        delete green[0];
        green[0]=NULL;

    }
    }
     if(green[1]!=NULL)
    {
     green1=green[1]->speed.x;
    if(green1>0)
    {
        delete green[1];
        green[1]=NULL;

    }
    }

     if(green[2]!=NULL)
     {
     green2=green[2]->speed.x;
     if(green2>0)
     {
        delete green[2];
         green[2]=NULL;

     }
     }

}
void MainWindow::restart_game()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void MainWindow::exit_game()
{
    this->hide();
}








