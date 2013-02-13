#ifndef OPTICALDEVICE_H
#define OPTICALDEVICE_H

#include <opencv2/core/core.hpp>
#include <QString>
#include <QObject>


/**
  Represents a generic optical device.
  This class models position, orientation, focal distance,
  retina size, aberrations, and other items common to both
  cameras and projectors.
  */

class OpticalDevice:public QObject
{
    Q_OBJECT
public:
    OpticalDevice();

    ~OpticalDevice();

    /** Sets the distortion vector for this device. */
    void setDistortion(cv::Mat k);

    /** Sets the 3×3 intrinsic matrix for this device.
        This matrix is of the form:
        <table>
            <tr><td>f<sub>x</sub></td>
                <td>α<sub>c</sub></td>
                <td>c<sub>x</sub></td></tr>
            <tr><td>0</td>
                <td>f<sub>y</sub></td>
                <td>c<sub>y</sub></td></tr>
            <tr><td>0</td>
                <td>0</td>
                <td>1</tr>
        </table>
        */
    void setIntrinsics(cv::Mat m);

    /** Set this device's name. */
    void setName(QString n);

    /** Update the orientation of this device. */
    void setOrientation(cv::Mat o);
    void setOrientation(cv::Vec3d r);

    /** Update the position of this device. */
    void setPosition(cv::Vec3d p);

    /** Set the resolution of this device. */
    void setResolution(int u,int v);

    /** Set the resolution of this device. */
    void setResolution(cv::Size s);

    /** Returns the distortion vector for this device. */
    cv::Mat getDistortion();

    /** Returns the intrinsic matrix for this device.
      Distortions, while intrinsic, are not handled here. */
    cv::Mat getIntrinsics();

    /** Returns the name of this device. */
    QString getName();

    /** Get the horizontal component of a vector with
        a unit forward component and passing through
        the image point <tt>(u,0)</tt>.*/
    double getNormalizedU(double u);

    /** Get the vertical component of a vector with
        a unit forward component and passing through
        the image point <tt>(0,v)</tt>.*/
    double getNormalizedV(double v);

    /** Returns the orientation of this device as a
    <a href="http://en.wikipedia.org/wiki/Rodrigues'_rotation_formula">
    Rodrigues rotation matrix</a>.*/
    cv::Mat getOrientation();

    /** Returns a unit vector which passes through this device's origin
      and the given pixel in its array. */
    cv::Mat getPixelRay(double u,double v);

    /** Returns a unit vector pointing in this device's "up" direction;
        i.e., in the direction of increasing <tt>v</tt>. */
    cv::Mat getUpVector();

    /** Returns a unit vector pointing in this device's "forward" direction;
        i.e., the local <tt>z</tt> axis. */
    cv::Mat getFwdVector();

    /** Returns the position in 3d space of this device. */
    cv::Vec3d getPosition();

    /** Returns the horizontal resolution of this device. */
    int getResolutionU();

    /** Returns the vertical resolution of this device. */
    int getResolutionV();

    /** Returns the resolution of this device.    */
    cv::Size getResolution();

    /**
      Returns the focal length of the camera as a multiple of the
      physical pixel size; i.e., for an 8.0 μm cell size, if this method
      returns 1000 then the focal length is 8.0 mm. */
    double getFocalLength();

    /** Sets the intrinsic matrix to the desired focal length. */
    void setFocalLength(double f);

    void setPrincipalPoint(double u, double v);

    double getPrincipalU();
    double getPrincipalV();

public slots:
    void deleteLater();

private:
    cv::Mat distortion;
    QString name;
    cv::Mat orientation;
    cv::Mat intrinsicMatrix;
    cv::Vec3d position;
    cv::Size resolution;

    double getNormalizedCoord(double u,double c);
};

#endif // OPTICALDEVICE_H
