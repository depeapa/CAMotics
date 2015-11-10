/******************************************************************************\

    CAMotics is an Open-Source simulation and CAM software.
    Copyright (C) 2011-2015 Joseph Coffland <joseph@cauldrondevelopment.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

\******************************************************************************/

#ifndef CAMOTICS_RENDER_JOB_H
#define CAMOTICS_RENDER_JOB_H

#include "RenderMode.h"

#include <camotics/contour/ContourGenerator.h>
#include <camotics/contour/GridTreeRef.h>

#include <cbang/os/Thread.h>
#include <cbang/os/Mutex.h>
#include <cbang/util/SmartLock.h>

namespace CAMotics {
  class RenderJob : public cb::Thread {

    cb::SmartPointer<ContourGenerator> generator;

    FieldFunction &func;
    GridTreeRef &tree;

  public:
    RenderJob(FieldFunction &func, RenderMode mode, GridTreeRef &tree);

    double getProgress() {return generator->getProgress();}

    // From Thread
    void run();
    void stop();
  };
}

#endif // CAMOTICS_RENDER_JOB_H

