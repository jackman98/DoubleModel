#include "engine.h"

Engine::Engine(QObject *parent) : QObject(parent)
{

}

Engine::Engine(QString horsepower, QString torque)
{
	setHorsepower(horsepower);
	setTorque(torque);
}

QString Engine::horsepower() const
{
	return m_horsepower;
}

QString Engine::torque() const
{
	return m_torque;
}

void Engine::setHorsepower(QString horsepower)
{
	if (m_horsepower == horsepower)
		return;

	m_horsepower = horsepower;
	emit horsepowerChanged(m_horsepower);
}

void Engine::setTorque(QString torque)
{
	if (m_torque == torque)
		return;

	m_torque = torque;
	emit torqueChanged(m_torque);
}
