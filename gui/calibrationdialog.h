#ifndef CALIBRATIONDIALOG_H
#define CALIBRATIONDIALOG_H

#include <QDialog>
#include "hardware/camera/qcamera.h"
#include "geom/calibrationcompiler.h"

namespace Ui {
class CalibrationDialog;
}
/// Two-pane calibration dialog that allows the user
/// to calibrate a stereo pair.
class CalibrationDialog : public QDialog
{
    Q_OBJECT
    
public:
    /// Create the dialog
    explicit CalibrationDialog(QWidget *parent = 0);
    /// Destroy the dialog
    ~CalibrationDialog();

signals:
    void debug(QString);

public slots:
    /// Take a snapshot
    void takeSnap();
    /// Run the calibration algorithm
    void calibrate();
    /// Reset; remove all frames and start over.
    void reset();
    /// Close the dialog.
    void close();
    /// Calibrate the projector.
    void calibrateProjector();
    /// Set left camera
    void setLeft(QCamera *cam);
    /// One of our cameras has captured a frame
    void frameCaptured(cv::Mat frame,QCamera* cam,QProjector::Pattern *pattern);
    /// Set right camera
    void setRight(QCamera *cam);
    /// Set projector
    void setProjector(QProjector *proj);
    /// Set binary capture
    void setBinary(BinaryCompiler *binary);

    void binaryFrameCaptured(cv::Mat,bool);

    void emitDebug(QString info);

    /// Set counter value
    void setCounter(uint ctr);
    /// Show the dialog
    void show();
    
private:
    /// UI
    Ui::CalibrationDialog *ui;
    /// left camera
    QCamera *left;
    /// right camera
    QCamera *right;
    /// calibrator
    CalibrationCompiler *calib;
    /// standard
    CalibrationStandard *standard;

    void stopStreaming();
    void startStreaming();

};

#endif // CALIBRATIONDIALOG_H
