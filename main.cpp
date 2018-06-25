#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "car.h"
#include "engine.h"
#include <QDebug>

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);
	QList<QObject *> engines;
	engines.append(new Engine("150", "200"));
	engines.append(new Engine("180", "220"));
	engines.append(new Engine("170", "180"));
	engines.append(new Engine("350", "600"));

	QList<QObject *> cars;
	cars.append(new Car("BMW", "M2", engines));
	cars.append(new Car("Audi", "A6", engines));
	cars.append(new Car("BMW", "M2", engines));
	cars.append(new Car("Audi", "A6", engines));

	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty("myModel", QVariant::fromValue(cars));
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}
