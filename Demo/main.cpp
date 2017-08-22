#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <qconsole.h>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	auto out = QConsole::qStdOut(&a);

	QConsole console;
	QObject::connect(&console, &QConsole::readyRead, [&](){
		auto data = console.readLine();
		out->write("Echo: " + data);
		if(data.contains("exit"))
			qApp->quit();
	});
	if(!console.open()) {
		qCritical() << console.errorString();
		return EXIT_FAILURE;
	}
	return a.exec();
}
