/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2018 OpenFOAM Foundation
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::dragModels::ShiZhu2011

Description
    

    Reference:
    \verbatim
       Zhansheng Shi, Wei Wang, Jinghai Li,
       A bubble-based EMMS model for gas–solid bubbling fluidization,
       Chemical Engineering Science,
       Volume 66, Issue 22,
       2011,
       Pages 5541-5555,
       ISSN 0009-2509,
       https://doi.org/10.1016/j.ces.2011.07.020. 
    \endverbatim

SourceFiles
    ShiZhu2011.C

\*---------------------------------------------------------------------------*/

#ifndef ShiZhu2011_H
#define ShiZhu2011_H

#include "dragModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class phasePair;

namespace dragModels
{


class Ergun;
class WenYu;


/*---------------------------------------------------------------------------*\
                           Class Zhu2008 Declaration
\*---------------------------------------------------------------------------*/

class ShiZhu2011
:
    public dragModel
{
    // Private data
     //- Ergun drag model
        autoPtr<Ergun> Ergun_;

        //- Wen Yu drag model
        autoPtr<WenYu> WenYu_;


        //- Residual Reynolds Number
        const dimensionedScalar residualRe_;

        const dimensionedScalar scaleFactor_;


public:

    //- Runtime type information
    TypeName("ShiZhu2011");


    // Constructors

        //- Construct from a dictionary and a phase pair
        ShiZhu2011
        (
            const dictionary& dict,
            const phasePair& pair,
            const bool registerObject
        );


    //- Destructor
    virtual ~ShiZhu2011();


    // Member Functions

        //- Drag coefficient
        virtual tmp<volScalarField> CdRe() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace dragModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
