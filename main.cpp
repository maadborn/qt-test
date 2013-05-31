#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QPoint>
#include <qmath.h>
#include <QTime>
#include <time.h>

qreal getRadAngle(const QPoint &from, const QPoint &to);
qreal radToDegree(const qreal radsAngle);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream qout(stdout);

    QTime curtime = QTime::currentTime();
    qsrand(curtime.msec());

    qint32 times = 0;
    qint32 first = INT_MIN, second = INT_MIN, third = INT_MIN, fourth = INT_MIN;
    const qint32 MAX = 9, MIN = 2;
    bool test1 = true, test2 = true, test3 = true;

    do {
        first = (qrand() % (MAX + 1 - MIN)) + MIN;
        second = (qrand() % (MAX + 1 - MIN)) + MIN;
        third = (qrand() % (MAX + 1 - MIN)) + MIN;
        fourth = (qrand() % (MAX + 1 - MIN)) + MIN;

        ++times;

        test1 = first != second;
        test2 = second != third;
        test3 = third != fourth;

    } while (test1 || test2 || test3);

    qout << "times = " << times << endl <<
            "test1 = " << test1 << endl <<
            "test2 = " << test2 << endl <<
            "test3 = " << test3 << endl <<
            "first = " << first << endl <<
            "second = " << second << endl <<
            "third = " << third << endl <<
            "fourth = " << fourth << endl;

//    QPoint from(0,0);
//    QPoint firstQ(126, 46);
//    QPoint secondQ(-126, 46);
//    QPoint thirdQ(-126, -46);
//    QPoint fourthQ(126, -46);

//    qreal first = getRadAngle(from, firstQ);
//    qreal second = getRadAngle(from, secondQ);
//    qreal third = getRadAngle(from, thirdQ);
//    qreal fourth = getRadAngle(from, fourthQ);

//    qDebug() << "First Quad:" << first << "rads," << radToDegree(first) << "degrees.";
//    qDebug() << "Seco. Quad:" << second << "rads," << radToDegree(second) << "degrees.";
//    qDebug() << "Third Quad:" << third << "rads," << radToDegree(third) << "degrees.";
//    qDebug() << "Four. Quad:" << fourth << "rads," << radToDegree(fourth) << "degrees.";

//    qreal radiansBetweenNodes = (M_PI / 180.0) * (360.0 / 6);
//    QVariant qv = radiansBetweenNodes;

//    qDebug() << qv.toString();
    
    //return a.exec();
}

qreal getRadAngle(const QPoint &from, const QPoint &to)
{
    // Get the distances
    qreal distX = (to.x() - from.x());
    qreal distY = (to.y() - from.y());

    qreal angleRad = atan2(distY, distX);

    // If the x distancs is 0, the angle is known, depending on the y distance
    // Also prevents division by zero in the arctangent calculation below
//    if (distX == 0) {
//        if (distY > 0)
//            return (M_PI / 2);
//        else
//            return -(M_PI / 2);
//    }

//    // If the y distancs is 0, the angle is known, depending on the x distance
//    if (distY == 0) {
//        if (distX > 0)
//            return 0;
//        else
//            return M_PI;
//    }

//    // Trigonometric arctangent calculation to get the angle
//    qreal quotient = distY / distX;
//    qreal angleRad = 1;
//    angleRad = qAtan(quotient);

//    // If the angle is in the 2nd or 3rd quadrant, add PI radians (180 degrees)
//    if (distX < 0)
//        angleRad += M_PI;

//    // Just for debugging.. degrees are a bit quicker to understand
//    //    qreal angleDeg = angleRad * (180.0 / M_PI);
//    //    Q_UNUSED(angleDeg);

    return angleRad;
}


qreal radToDegree(const qreal radsAngle) {
    return radsAngle * (180 / M_PI);
}
