#pragma once
#include <QObject>
#include <QByteArray>

class Datagram : public QObject {
	Q_OBJECT

public:
	Datagram(QByteArray& data);
	~Datagram();
	void process();
private:
	QByteArray localData;
signals:
	void putLog(const QString& s);
};
