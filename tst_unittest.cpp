#include <QString>
#include <QtTest>

#include "../ST_test/baseworker.h"
#include "../ST_test/employeeworker.h"
#include "../ST_test/managerworker.h"
#include "../ST_test/salesworker.h"
#include "../ST_test/databaseadapter.h"

class UnitTest : public QObject
{
    Q_OBJECT

public:
    UnitTest();

private Q_SLOTS:

    //Тесты для класса Employee
    void calculateEmploeePay_test1();
    void calculateEmploeePay_test2();
    void calculateEmploeePay_11years_test();
    void EmploeePay_setMaster_test();

    //Тесты для класса Manage
    void calculateManagePay_test1();
    void calculateManagePay_test2();
    void calculateManagePay_test3();
    void calculateManagePay_11years_test();
    void Manage_setMaster_test();

    //Тесты для класса Sales
    void calculateSalesPay_test1();
    void calculateSalesPay_test2();
};

UnitTest::UnitTest()
{
}

void UnitTest::calculateEmploeePay_test1()
{
    EmployeeWorker testWorker("Петров Иван Александрович",10000,QDate::fromString("01.06.2012","dd.MM.yyyy"));

    double pay = testWorker.calculatePay(QDate::currentDate());

    QVERIFY(pay == 11800.0);
}


void UnitTest::calculateEmploeePay_test2()
{
    EmployeeWorker testWorker("Петров Иван Александрович",10000,QDate::fromString("01.01.2012","dd.MM.yyyy"));

    double pay = testWorker.calculatePay(QDate::currentDate());

    QVERIFY(pay == 12100);
}

void UnitTest::calculateEmploeePay_11years_test()
{
    EmployeeWorker testWorker("Петров Иван Александрович",10000,QDate::fromString("01.01.1995","dd.MM.yyyy"));

    double pay = testWorker.calculatePay(QDate::currentDate());

    QVERIFY(pay == 13000);
}

void UnitTest::EmploeePay_setMaster_test()
{
    BaseWorker * master;
    ManagerWorker manager("Петров Александр Евгеньевич",15000,QDate::fromString("01.01.1995","dd.MM.yyyy"));
    SalesWorker   sales("Петров Евгений Петрович",15000,QDate::fromString("01.01.1995","dd.MM.yyyy"));

    EmployeeWorker testWorker("Петров Иван Александрович",10000,QDate::fromString("01.01.2013","dd.MM.yyyy"));

    testWorker.setMaster(&manager);
    master = testWorker.getMaster();
    QVERIFY(master->getName() == "Петров Александр Евгеньевич");

    testWorker.setMaster(&sales);
    master = testWorker.getMaster();
    QVERIFY(master->getName() == "Петров Евгений Петрович");
}

void UnitTest::calculateManagePay_test1()
{
    ManagerWorker testWorker("Петров Иван Александрович",15000,QDate::fromString("01.01.2012","dd.MM.yyyy"));

    double pay = testWorker.calculatePay(QDate::currentDate());

    QVERIFY(pay == 20250);
}

void UnitTest::calculateManagePay_test2()
{
    EmployeeWorker subWorker1("Лукьянов Иван Александрович"  ,10000,QDate::fromString("01.01.2010","dd.MM.yyyy"));
    EmployeeWorker subWorker2("Соколов Николай Александрович",11000,QDate::fromString("01.01.2015","dd.MM.yyyy"));
    EmployeeWorker subWorker3("Попов Андрей Александрович"   ,12000,QDate::fromString("01.01.2016","dd.MM.yyyy"));

    ManagerWorker testWorker("Петров Иван Александрович",15000,QDate::fromString("01.01.2012","dd.MM.yyyy"));
    testWorker.addSubordinate(&subWorker1);
    testWorker.addSubordinate(&subWorker2);
    testWorker.addSubordinate(&subWorker3);

    double pay = testWorker.calculatePay(QDate::currentDate());

    QVERIFY(pay == 20440.5);
}

void UnitTest::calculateManagePay_test3()
{
    EmployeeWorker subWorker1("Лукьянов Иван Александрович"  ,10000,QDate::fromString("01.01.2010","dd.MM.yyyy"));
    EmployeeWorker subWorker2("Соколов Николай Александрович",11000,QDate::fromString("01.01.2015","dd.MM.yyyy"));
    EmployeeWorker subWorker3("Попов Андрей Александрович"   ,12000,QDate::fromString("01.01.2016","dd.MM.yyyy"));

    ManagerWorker testWorker("Петров Иван Александрович",15000,QDate::fromString("01.01.2012","dd.MM.yyyy"));
    testWorker.addSubordinate(&subWorker1);
    testWorker.addSubordinate(&subWorker2);
    testWorker.addSubordinate(&subWorker3);

    QList<BaseWorker*> subordinates = testWorker.getSubordinates();

    QVERIFY(subordinates[0]->getName() == "Лукьянов Иван Александрович");
    QVERIFY(subordinates[1]->getName() == "Соколов Николай Александрович");
    QVERIFY(subordinates[2]->getName() == "Попов Андрей Александрович");
}

void UnitTest::calculateManagePay_11years_test()
{
    ManagerWorker testWorker("Петров Иван Александрович",15000,QDate::fromString("01.01.1995","dd.MM.yyyy"));

    double pay = testWorker.calculatePay(QDate::currentDate());

    QVERIFY(pay == 21000);
}

void UnitTest::Manage_setMaster_test()
{
    BaseWorker * master;
    SalesWorker   sales("Петров Евгений Петрович",15000,QDate::fromString("01.01.1995","dd.MM.yyyy"));
    ManagerWorker testWorker("Петров Иван Александрович",15000,QDate::fromString("01.01.1995","dd.MM.yyyy"));

    testWorker.setMaster(&sales);
    master = testWorker.getMaster();

    QVERIFY(master->getName() == "Петров Евгений Петрович");
}

void UnitTest::calculateSalesPay_test1()
{
    SalesWorker testWorker("Петров Иван Александрович",20000,QDate::fromString("01.06.2012","dd.MM.yyyy"));

    double pay = testWorker.calculatePay(QDate::currentDate());

    QVERIFY(pay == 21200.0);
}

void UnitTest::calculateSalesPay_test2()
{
    EmployeeWorker subWorker1("Лукьянов Иван Александрович"  ,10000,QDate::fromString("01.01.2010","dd.MM.yyyy"));
    EmployeeWorker subWorker2("Соколов Николай Александрович",11000,QDate::fromString("01.01.2015","dd.MM.yyyy"));
    EmployeeWorker subWorker3("Попов Андрей Александрович"   ,12000,QDate::fromString("01.01.2016","dd.MM.yyyy"));

    ManagerWorker subworker4("Петров Иван Александрович",15000,QDate::fromString("01.01.2012","dd.MM.yyyy"));
    subworker4.addSubordinate(&subWorker1);
    subworker4.addSubordinate(&subWorker2);
    subworker4.addSubordinate(&subWorker3);

    SalesWorker testWorker("Петров Иван Александрович",20000,QDate::fromString("01.06.2012","dd.MM.yyyy"));
    testWorker.addSubordinate(&subworker4);

    double pay = testWorker.calculatePay(QDate::currentDate());

    QVERIFY(pay == 22956.215);
}

QTEST_APPLESS_MAIN(UnitTest)

#include "tst_unittest.moc"
