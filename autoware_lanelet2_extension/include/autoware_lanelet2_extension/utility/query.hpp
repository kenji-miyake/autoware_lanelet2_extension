// Copyright 2015-2019 Autoware Foundation. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Authors: Simon Thompson, Ryohsuke Mitsudome

#ifndef AUTOWARE_LANELET2_EXTENSION__UTILITY__QUERY_HPP_
#define AUTOWARE_LANELET2_EXTENSION__UTILITY__QUERY_HPP_

// NOLINTBEGIN(readability-identifier-naming)

#include "autoware_lanelet2_extension/regulatory_elements/autoware_traffic_light.hpp"
#include "autoware_lanelet2_extension/regulatory_elements/crosswalk.hpp"
#include "autoware_lanelet2_extension/regulatory_elements/detection_area.hpp"
#include "autoware_lanelet2_extension/regulatory_elements/no_parking_area.hpp"
#include "autoware_lanelet2_extension/regulatory_elements/no_stopping_area.hpp"
#include "autoware_lanelet2_extension/regulatory_elements/speed_bump.hpp"

#include <geometry_msgs/msg/point.hpp>
#include <geometry_msgs/msg/pose.hpp>

#include <lanelet2_core/LaneletMap.h>
#include <lanelet2_core/primitives/Lanelet.h>
#include <lanelet2_routing/RoutingGraph.h>

#include <limits>
#include <string>
#include <vector>

namespace lanelet::utils::query
{

inline namespace format_v2
{
/**
 * [crosswalkLanelets extracts crosswalk lanelets]
 * @param  lls [input lanelets with various subtypes]
 * @return     [crosswalk lanelets]
 */
lanelet::ConstLanelets crosswalkLanelets(const lanelet::ConstLanelets & lls);
lanelet::ConstLanelets walkwayLanelets(const lanelet::ConstLanelets & lls);

/**
 * [shoulderLanelets extracts shoulder lanelets]
 * @param  lls [input lanelets with subtype shoulder]
 * @return     [shoulder lanelets]
 */
lanelet::ConstLanelets shoulderLanelets(const lanelet::ConstLanelets & lls);

/**
 * [bicycleLaneLanelets extracts shoulder lanelets]
 * @param  lls [input lanelets possibly with subtype bicycle_lane]
 * @return     [shoulder lanelets]
 */
lanelet::ConstLanelets bicycleLaneLanelets(const lanelet::ConstLanelets & lls);

/**
 * [trafficLights extracts Traffic Light regulatory element from lanelets]
 * @param lanelets [input lanelets]
 * @return         [traffic light that are associated with input lanelets]
 */
std::vector<lanelet::TrafficLightConstPtr> trafficLights(const lanelet::ConstLanelets & lanelets);

/**
 * [autowareTrafficLights extracts Autoware Traffic Light regulatory element
 * from lanelets]
 * @param lanelets [input lanelets]
 * @return         [autoware traffic light that are associated with input
 * lanelets]
 */
std::vector<lanelet::AutowareTrafficLightConstPtr> autowareTrafficLights(
  const lanelet::ConstLanelets & lanelets);

/**
 * [detectionAreas extracts Detection Area regulatory elements from lanelets]
 * @param lanelets [input lanelets]
 * @return         [detection areas that are associated with input lanelets]
 */
std::vector<lanelet::DetectionAreaConstPtr> detectionAreas(const lanelet::ConstLanelets & lanelets);

/**
 * [noStoppingArea extracts NoStopping Area regulatory elements from lanelets]
 * @param lanelets [input lanelets]
 * @return         [no stopping areas that are associated with input lanelets]
 */
std::vector<lanelet::NoStoppingAreaConstPtr> noStoppingAreas(
  const lanelet::ConstLanelets & lanelets);

/**
 * [noParkingArea extracts NoParking Area regulatory elements from lanelets]
 * @param lanelets [input lanelets]
 * @return         [no parking areas that are associated with input lanelets]
 */
std::vector<lanelet::NoParkingAreaConstPtr> noParkingAreas(const lanelet::ConstLanelets & lanelets);

/**
 * [busStopArea extracts BusStop Area regulatory elements from lanelets]
 * @param lanelets [input lanelets]
 * @return         [bus stop areas that are associated with input lanelets]
 */
std::vector<lanelet::BusStopAreaConstPtr> busStopAreas(const lanelet::ConstLanelets & lanelets);

/**
 * [speedBumps extracts Speed Bump regulatory elements from lanelets]
 * @param lanelets [input lanelets]
 * @return         [speed bumps that are associated with input lanelets]
 */
std::vector<lanelet::SpeedBumpConstPtr> speedBumps(const lanelet::ConstLanelets & lanelets);

/**
 * [crosswalks extracts Crosswalk regulatory elements from lanelets]
 * @param lanelets [input lanelets]
 * @return         [crosswalks that are associated with input lanelets]
 */
std::vector<lanelet::CrosswalkConstPtr> crosswalks(const lanelet::ConstLanelets & lanelets);

// query all curbstones in lanelet2 map
lanelet::ConstLineStrings3d curbstones(const lanelet::LaneletMapConstPtr & lanelet_map_ptr);

// query all obstacle polygons in lanelet2 map
lanelet::ConstPolygons3d getAllObstaclePolygons(
  const lanelet::LaneletMapConstPtr & lanelet_map_ptr);

// query all parking lots in lanelet2 map
lanelet::ConstPolygons3d getAllParkingLots(const lanelet::LaneletMapConstPtr & lanelet_map_ptr);

// query all linestrings with defined type in lanelet2 map
lanelet::ConstLineStrings3d getAllLinestringsWithType(
  const lanelet::LaneletMapConstPtr & lanelet_map_ptr, const std::string & type);

// query all partitions in lanelet2 map
lanelet::ConstLineStrings3d getAllPartitions(const lanelet::LaneletMapConstPtr & lanelet_map_ptr);

// query all fences in lanelet2 map
lanelet::ConstLineStrings3d getAllFences(const lanelet::LaneletMapConstPtr & lanelet_map_ptr);

// query all pedestrian polygon markings in lanelet2 map
lanelet::ConstLineStrings3d getAllPedestrianPolygonMarkings(
  const lanelet::LaneletMapConstPtr & lanelet_map_ptr);

// query all pedestrian line markings in lanelet2 map
lanelet::ConstLineStrings3d getAllPedestrianLineMarkings(
  const lanelet::LaneletMapConstPtr & lanelet_map_ptr);

// query all parking spaces in lanelet2 map
lanelet::ConstLineStrings3d getAllParkingSpaces(
  const lanelet::LaneletMapConstPtr & lanelet_map_ptr);

// query all waypoints in lanelet2 map
lanelet::ConstLineStrings3d getAllWaypoints(const lanelet::LaneletMapConstPtr & lanelet_map_ptr);

// query linked parking spaces from lanelet
lanelet::ConstLineStrings3d getLinkedParkingSpaces(
  const lanelet::ConstLanelet & lanelet, const lanelet::LaneletMapConstPtr & lanelet_map_ptr);
lanelet::ConstLineStrings3d getLinkedParkingSpaces(
  const lanelet::ConstLanelet & lanelet, const lanelet::ConstLineStrings3d & all_parking_spaces,
  const lanelet::ConstPolygons3d & all_parking_lots);
// query linked lanelets from parking space
bool getLinkedLanelet(
  const lanelet::ConstLineString3d & parking_space,
  const lanelet::ConstLanelets & all_road_lanelets,
  const lanelet::ConstPolygons3d & all_parking_lots, lanelet::ConstLanelet * linked_lanelet);
bool getLinkedLanelet(
  const lanelet::ConstLineString3d & parking_space,
  const lanelet::LaneletMapConstPtr & lanelet_map_ptr, lanelet::ConstLanelet * linked_lanelet);
lanelet::ConstLanelets getLinkedLanelets(
  const lanelet::ConstLineString3d & parking_space,
  const lanelet::ConstLanelets & all_road_lanelets,
  const lanelet::ConstPolygons3d & all_parking_lots);
lanelet::ConstLanelets getLinkedLanelets(
  const lanelet::ConstLineString3d & parking_space,
  const lanelet::LaneletMapConstPtr & lanelet_map_ptr);

// get linked parking lot from lanelet
bool getLinkedParkingLot(
  const lanelet::ConstLanelet & lanelet, const lanelet::ConstPolygons3d & all_parking_lots,
  lanelet::ConstPolygon3d * linked_parking_lot);
// get linked parking lot from current pose of ego car
bool getLinkedParkingLot(
  const lanelet::BasicPoint2d & current_position, const lanelet::ConstPolygons3d & all_parking_lots,
  lanelet::ConstPolygon3d * linked_parking_lot);
bool getLinkedParkingLot(
  const lanelet::BasicPoint2d & current_position,
  const lanelet::LaneletMapConstPtr & lanelet_map_ptr,
  lanelet::ConstPolygon3d * linked_parking_lot);
// get linked parking lot from parking space
bool getLinkedParkingLot(
  const lanelet::ConstLineString3d & parking_space,
  const lanelet::ConstPolygons3d & all_parking_lots, lanelet::ConstPolygon3d * linked_parking_lot);

// query linked parking space from parking lot
lanelet::ConstLineStrings3d getLinkedParkingSpaces(
  const lanelet::ConstPolygon3d & parking_lot,
  const lanelet::ConstLineStrings3d & all_parking_spaces);
// query linked lanelets from parking lot
lanelet::ConstLanelets getLinkedLanelets(
  const lanelet::ConstPolygon3d & parking_lot, const lanelet::ConstLanelets & all_road_lanelets);

/**
 * [stopLinesLanelets extracts stoplines that are associated to lanelets]
 * @param lanelets [input lanelets]
 * @return         [stop lines that are associated with input lanelets]
 */
std::vector<lanelet::ConstLineString3d> stopLinesLanelets(const lanelet::ConstLanelets & lanelets);

/**
 * [stopLinesLanelet extracts stop lines that are associated with a given
 * lanelet]
 * @param ll [input lanelet]
 * @return   [stop lines that are associated with input lanelet]
 */
std::vector<lanelet::ConstLineString3d> stopLinesLanelet(const lanelet::ConstLanelet & ll);

/**
 * [stopSignStopLines extracts stoplines that are associated with stop signs]
 * @param lanelets     [input lanelets]
 * @param stop_sign_id [sign id of stop sign]
 * @return             [array of stoplines]
 */
std::vector<lanelet::ConstLineString3d> stopSignStopLines(
  const lanelet::ConstLanelets & lanelets, const std::string & stop_sign_id = "stop_sign");
}  // namespace format_v2

/**
 * [laneletLayer converts laneletLayer into lanelet vector]
 * @param  ll_Map [input lanelet map]
 * @return        [all lanelets in the map]
 */
lanelet::ConstLanelets laneletLayer(const lanelet::LaneletMapConstPtr & ll_Map);

/**
 * [subtypeLanelets extracts Lanelet that has given subtype attribute]
 * @param  lls     [input lanelets with various subtypes]
 * @param  subtype [subtype of lanelets to be retrieved (e.g.
 * lanelet::AttributeValueString::Road)]
 * @return         [lanelets with given subtype]
 */
lanelet::ConstLanelets subtypeLanelets(const lanelet::ConstLanelets & lls, const char subtype[]);

/**
 * [roadLanelets extracts road lanelets]
 * @param  lls [input lanelets with subtype road]
 * @return     [road lanelets]
 */
lanelet::ConstLanelets roadLanelets(const lanelet::ConstLanelets & lls);

// query all polygons that has given type in lanelet2 map
lanelet::ConstPolygons3d getAllPolygonsByType(
  const lanelet::LaneletMapConstPtr & lanelet_map_ptr, const std::string & polygon_type);

ConstLanelets getLaneletsWithinRange(
  const lanelet::ConstLanelets & lanelets, const lanelet::BasicPoint2d & search_point,
  const double range);
ConstLanelets getLaneletsWithinRange(
  const lanelet::ConstLanelets & lanelets, const geometry_msgs::msg::Point & search_point,
  const double range);

ConstLanelets getLaneChangeableNeighbors(
  const routing::RoutingGraphPtr & graph, const ConstLanelet & lanelet);
ConstLanelets getLaneChangeableNeighbors(
  const routing::RoutingGraphPtr & graph, const ConstLanelets & road_lanelets,
  const geometry_msgs::msg::Point & search_point);

ConstLanelets getAllNeighbors(const routing::RoutingGraphPtr & graph, const ConstLanelet & lanelet);
ConstLanelets getAllNeighborsLeft(
  const routing::RoutingGraphPtr & graph, const ConstLanelet & lanelet);
ConstLanelets getAllNeighborsRight(
  const routing::RoutingGraphPtr & graph, const ConstLanelet & lanelet);
ConstLanelets getAllNeighbors(
  const routing::RoutingGraphPtr & graph, const ConstLanelets & road_lanelets,
  const geometry_msgs::msg::Point & search_point);

bool getClosestLanelet(
  const ConstLanelets & lanelets, const geometry_msgs::msg::Pose & search_pose,
  ConstLanelet * closest_lanelet_ptr);

bool getClosestLaneletWithConstrains(
  const ConstLanelets & lanelets, const geometry_msgs::msg::Pose & search_pose,
  ConstLanelet * closest_lanelet_ptr,
  const double dist_threshold = std::numeric_limits<double>::max(),
  const double yaw_threshold = std::numeric_limits<double>::max());

bool getCurrentLanelets(
  const ConstLanelets & lanelets, const geometry_msgs::msg::Point & search_point,
  ConstLanelets * current_lanelets_ptr);

bool getCurrentLanelets(
  const ConstLanelets & lanelets, const geometry_msgs::msg::Pose & search_pose,
  ConstLanelets * current_lanelets_ptr);

/**
 * [getSucceedingLaneletSequences retrieves a sequence of lanelets after the given lanelet.
 * The total length of retrieved lanelet sequence at least given length. Returned lanelet sequence
 * does not include input lanelet.]
 * @param graph [input lanelet routing graph]
 * @param lanelet [input lanelet]
 * @param length [minimum length of retrieved lanelet sequence]
 * @return   [lanelet sequence that follows given lanelet]
 */
std::vector<lanelet::ConstLanelets> getSucceedingLaneletSequences(
  const routing::RoutingGraphPtr & graph, const lanelet::ConstLanelet & lanelet,
  const double length);

/**
 * [getPrecedingLaneletSequences retrieves a sequence of lanelets before the given lanelet.
 * The total length of retrieved lanelet sequence at least given length. Returned lanelet sequence
 * does not include input lanelet.]
 * @param graph [input lanelet routing graph]
 * @param lanelet [input lanelet]
 * @param length [minimum length of retrieved lanelet sequence]
 * @return   [lanelet sequence that leads to given lanelet]
 */
std::vector<lanelet::ConstLanelets> getPrecedingLaneletSequences(
  const routing::RoutingGraphPtr & graph, const lanelet::ConstLanelet & lanelet,
  const double length, const lanelet::ConstLanelets & exclude_lanelets = {});

}  // namespace lanelet::utils::query

// NOLINTEND(readability-identifier-naming)

#endif  // AUTOWARE_LANELET2_EXTENSION__UTILITY__QUERY_HPP_
