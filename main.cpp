#include <QtGui/QtGui>
#include <QtWidgets/qtextedit.h>
#include <QtWebKit/QtWebKit>
#include <QtWebKitWidgets/QtWebKitWidgets>


class MWebView : public QWebView{
    virtual QWebView *createWindow(QWebPage::WebWindowType type){
    	auto newView = new MWebView();
    	newView->show();
    	return newView;
    }
};


int main(int argc, char** argv) {
    QApplication app(argc, argv);
    MWebView view;


	if (argc > 1) {
	    view.setUrl(QUrl(argv[1]));
	}
    view.show();
    view.settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    view.settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    view.settings()->setOfflineStoragePath("cache");

    return app.exec();
}
