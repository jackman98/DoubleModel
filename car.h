#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QString>

class Car : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString brand READ brand WRITE setBrand NOTIFY brandChanged)
	Q_PROPERTY(QString model READ model WRITE setModel NOTIFY modelChanged)
	Q_PROPERTY(QList<QObject *> engines READ engines WRITE setEngines NOTIFY enginesChanged)

public:
	explicit Car(QObject *parent = nullptr);

	Car(QString brand, QString model, QList<QObject *> engines);

	QString brand() const;
	QString model() const;
	QList<QObject *> engines() const;

signals:
	void brandChanged(QString brand);
	void modelChanged(QString model);
	void enginesChanged(QList<QObject *> engines);

public slots:
	void setBrand(QString brand);
	void setModel(QString model);
	void setEngines(QList<QObject *> engines);

private:
	QString m_brand;
	QString m_model;
	QList<QObject *> m_engines;
};

#endif // CAR_H
