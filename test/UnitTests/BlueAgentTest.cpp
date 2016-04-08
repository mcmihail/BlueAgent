#include <QString>
#include <QtTest>

class BlueAgentTest : public QObject
{
    Q_OBJECT

public:
    BlueAgentTest();

private Q_SLOTS:
    void testConstructor();
};

BlueAgentTest::BlueAgentTest()
{
}

void BlueAgentTest::testConstructor()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(BlueAgentTest)

#include "BlueAgentTest.moc"
