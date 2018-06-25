#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>

class Engine : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString horsepower READ horsepower WRITE setHorsepower NOTIFY horsepowerChanged)
	Q_PROPERTY(QString torque READ torque WRITE setTorque NOTIFY torqueChanged)

public:
	explicit Engine(QObject *parent = nullptr);
	Engine(QString horsepower, QString torque);

	QString horsepower() const;
	QString torque() const;

signals:
	void horsepowerChanged(QString horsepower);
	void torqueChanged(QString torque);

public slots:
	void setHorsepower(QString horsepower);
	void setTorque(QString torque);
private:
	QString m_horsepower;
	QString m_torque;
};

#endif // ENGINE_H
