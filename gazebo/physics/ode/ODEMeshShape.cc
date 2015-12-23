/*
 * Copyright (C) 2012-2015 Open Source Robotics Foundation
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
#include "gazebo/common/Mesh.hh"
#include "gazebo/common/Assert.hh"
#include "gazebo/common/Console.hh"

#include "gazebo/physics/ode/ODEMesh.hh"
#include "gazebo/physics/ode/ODECollision.hh"
#include "gazebo/physics/ode/ODEPhysics.hh"
#include "gazebo/physics/MeshShapePrivate.hh"
#include "gazebo/physics/ode/ODEMeshShape.hh"

using namespace gazebo;
using namespace physics;

//////////////////////////////////////////////////
ODEMeshShape::ODEMeshShape(CollisionPtr _parent) : MeshShape(_parent)
{
  this->odeMesh = new ODEMesh();
}

//////////////////////////////////////////////////
ODEMeshShape::~ODEMeshShape()
{
  delete this->odeMesh;
}

//////////////////////////////////////////////////
void ODEMeshShape::Update()
{
  this->odeMesh->Update();
}

//////////////////////////////////////////////////
void ODEMeshShape::Load(sdf::ElementPtr _sdf)
{
  MeshShape::Load(_sdf);
}

//////////////////////////////////////////////////
void ODEMeshShape::Init()
{
  MeshShape::Init();
  if (!this->meshShapeDPtr->mesh)
    return;

  if (this->meshShapeDPtr->submesh)
  {
    this->odeMesh->Init(this->meshShapeDPtr->submesh,
        std::static_pointer_cast<ODECollision>(
          this->meshShapeDPtr->collisionParent),
        this->meshShapeDPtr->sdf->Get<ignition::math::Vector3d>("scale"));
  }
  else
  {
    this->odeMesh->Init(this->meshShapeDPtr->mesh,
        std::static_pointer_cast<ODECollision>(
          this->meshShapeDPtr->collisionParent),
        this->meshShapeDPtr->sdf->Get<ignition::math::Vector3d>("scale"));
  }
}
