#ifndef CHANGERESOLUTIONDIALOG_H
#define CHANGERESOLUTIONDIALOG_H

#include <QDialog>

#include "../hardware/camera/qcamera.h"

namespace Ui {
class ChangeResolutionDialog;
}

class ChangeResolutionDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ChangeResolutionDialog(QWidget *parent = 0);
    ~ChangeResolutionDialog();
    void setCamera(QCamera *cam);

public slots:
    void accept();
    void reject();

signals:
    void resolutionChanged(int u, int v);
    
private:
    Ui::ChangeResolutionDialog *ui;
    QCamera *camera;
};

#endif // CHANGERESOLUTIONDIALOG_H
