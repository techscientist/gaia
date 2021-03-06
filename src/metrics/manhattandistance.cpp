/* 
 * Copyright (C) 2006-2013  Music Technology Group - Universitat Pompeu Fabra
 *
 * This file is part of Gaia
 * 
 * Gaia is free software: you can redistribute it and/or modify it under 
 * the terms of the GNU Affero General Public License as published by the Free 
 * Software Foundation (FSF), either version 3 of the License, or (at your 
 * option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS 
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more 
 * details.
 * 
 * You should have received a copy of the Affero GNU General Public License
 * version 3 along with this program.  If not, see http://www.gnu.org/licenses/
 */

#include "manhattandistance.h"
#include "../utils.h"
using namespace gaia2;

ManhattanDistance::ManhattanDistance(const PointLayout& layout,
                                     const ParameterMap& params) : DistanceFunction(layout, params) {

  _region = checkFixedLength(_region.select(RealType));
}

Real ManhattanDistance::operator()(const Point& p1, const Point& p2, int seg1, int seg2) const {
  Real dist = 0.0;

  const RealDescriptor& fldescs1 = p1.frealData(seg1);
  const RealDescriptor& fldescs2 = p2.frealData(seg2);

  for (int i=0; i<_region.segments.size(); i++) {
    const Segment& segment = _region.segments[i];
    for (int j=segment.begin; j<segment.end; j++) {
      Real d = fldescs1[j] - fldescs2[j];
      dist += qAbs(d);
    }
  }

  return dist;
}
