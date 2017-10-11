#include "normaldiffusealphaobject.h"
#include <QTextureWrapMode>
#include <QAbstractTexture>

SolarSystem::NormalDiffuseAlphaObject::NormalDiffuseAlphaObject(Qt3DCore::QNode* parent):
    Solar3dObject(parent)
{
    _materialType = SolarMaterials::NormalDiffuseAplha;
    _material = new Qt3DExtras::QNormalDiffuseMapAlphaMaterial();

    auto mat = qobject_cast<Qt3DExtras::QNormalDiffuseMapAlphaMaterial*>(_material);
    Qt3DRender::QTextureWrapMode wrapMode;

    mat->diffuse()->setWrapMode(wrapMode);
    mat->diffuse()->setGenerateMipMaps(true);
    mat->diffuse()->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
    mat->diffuse()->setMinificationFilter(Qt3DRender::QAbstractTexture::LinearMipMapLinear);
    mat->diffuse()->setMaximumAnisotropy(16.0f);

    mat->normal()->setWrapMode(wrapMode);
    mat->normal()->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
    mat->normal()->setMinificationFilter(Qt3DRender::QAbstractTexture::Linear);
    mat->normal()->setMaximumAnisotropy(16.0f);

    mat->setShininess(0);
    mat->setSpecular(QColor(qRgba(0,0,0,255)));
    mat->setAmbient(QColor(qRgba(10,10,10,255)));
    mat->setTextureScale(1.0f);

    _picker->setEnabled(false);

    addComponent(_material);
}