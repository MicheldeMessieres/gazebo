/*
 * Copyright (C) 2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef _GAZEBO_PHYSICS_ODE_ODELINK_PRIVATE_HH_
#define _GAZEBO_PHYSICS_ODE_ODELINK_PRIVATE_HH_

#include <ignition/math/Vector3.hh>

#include "gazebo/physics/ode/ode_inc.h"
#include "gazebo/physics/ode/ODETypes.hh"
#include "gazebo/physics/LinkPrivate.hh"
#include "gazebo/util/system.hh"

namespace gazebo
{
  namespace physics
  {
    /// \internal
    /// \brief ODELink private data
    class ODELinkPrivate : public LinkPrivate
    {
      /// \brief ODE link handle
      public: dBodyID linkId;

      /// \brief Pointer to the ODE Physics engine
      public: ODEPhysicsPtr odePhysics;

      /// \brief Collision space id.
      public: dSpaceID spaceId;

      /// \brief Cache force applied on body
      public: ignition::math::Vector3d force;

      /// \brief Cache torque applied on body
      public: ignition::math::Vector3d torque;
    };
  }
}
#endif
