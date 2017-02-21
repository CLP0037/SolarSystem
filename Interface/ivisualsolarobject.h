#ifndef IVISUALSOLAROBJECT_H
#define IVISUALSOLAROBJECT_H

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DRender/QMesh>
#include <Qt3DRender/QObjectPicker>
#include <vector>
#include <functional>
#include <solarsystemcore.h>

namespace SolarSystem {

    //types
    using LogicPtr = std::function<void(float)>;
    using Logic = std::vector<LogicPtr>;

    //interface for base visual object on the scene
    class IVisualSolarObject : public Qt3DCore::QEntity {

        Q_OBJECT

    public:

        //constructors
        IVisualSolarObject(Qt3DCore::QNode* parent = 0);
        virtual ~IVisualSolarObject();

    protected:

        //frame tick for solar object logic programming
        virtual void update(float deltaTime) = 0;

    public:

        //logic
        virtual void addLogic(LogicPtr func) = 0;
        virtual void clearLogic() = 0;

        //position in space
        virtual Qt3DCore::QTransform& transform() const = 0;

        //get mesh
        virtual Qt3DRender::QMesh& mesh() const =0;

        //get picker
        virtual Qt3DRender::QObjectPicker& picker() const = 0;

        /*//returns current object type
        virtual SolarObjects solarType() const = 0;

        //set solar type
        virtual void setSolarType(SolarObjects type) = 0;

        float r() const;
        void setR(float r);

        float x() const;
        void setX(float x);

        float y() const;
        void setY(float y);

        float z() const;
        void setZ(float z);

        float roll() const;
        void setRoll(float roll);

        float tilt() const;
        void setTilt(float tilt);*/
    };

}

#endif // IVISUALSOLAROBJECT_H
