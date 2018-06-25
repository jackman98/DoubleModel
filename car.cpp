#include "car.h"
#include <QDebug>

Car::Car(QObject *parent) : QObject(parent)
{

}

Car::Car(QString brand, QString model, QList<QObject *> engines)
{
	setBrand(brand);
	setModel(model);
	setEngines(engines);
}

QString Car::brand() const
{
	return m_brand;
}

QString Car::model() const
{
	return m_model;
}

QList<QObject *> Car::engines() const
{
	return m_engines;
}

void Car::setBrand(QString brand)
{
	if (m_brand == brand)
		return;

	m_brand = brand;
	emit brandChanged(m_brand);
}

void Car::setModel(QString model)
{
	if (m_model == model)
		return;

	m_model = model;
	emit modelChanged(m_model);
}

void Car::setEngines(QList<QObject *> engines)
{
	if (m_engines == engines)
		return;

	m_engines = engines;
	emit enginesChanged(m_engines);
}
