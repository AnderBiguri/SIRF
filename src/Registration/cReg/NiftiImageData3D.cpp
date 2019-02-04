/*
CCP PETMR Synergistic Image Reconstruction Framework (SIRF)
Copyright 2017 - 2019 University College London

This is software developed for the Collaborative Computational
Project in Positron Emission Tomography and Magnetic Resonance imaging
(http://www.ccppetmr.ac.uk/).

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

/*!
\file
\ingroup Registration
\brief Base class for 3D SIRF image data.

\author Richard Brown
\author CCP PETMR
*/

#include "sirf/cReg/NiftiImageData3D.h"
#include <_reg_tools.h>
#include "sirf/cReg/AffineTransformation.h"

using namespace sirf;

template<class dataType>
NiftiImageData3D<dataType>::NiftiImageData3D(const ImageData& id)
{
    this->_nifti_image = NiftiImageData<float>::create_from_geom_info(*id.get_geom_info_sptr());

    // Always float
    this->set_up_data(NIFTI_TYPE_FLOAT32);

    // Finally, copy the data
    this->copy(id.begin(), this->begin(), this->end());
}

namespace sirf {
template class NiftiImageData3D<float>;
}
