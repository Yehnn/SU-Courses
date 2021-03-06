#ifndef META_NAVIGATOR_H
#define META_NAVIGATOR_H
/////////////////////////////////////////////////////////////////////////
//  MetaNavigator.h  -  Navigate metadata xml files and print file info//
//  ver 1.0                                                            //
//  Language:       Visual C++, ver 6.0                                //
//  Platform:       MacBook Pro, Windows7 Pro				           //
//  Application:    CSE687 project #2	                               //
//  Author:         Ider Zheng, Syracuse University					   //
//                  (315) 560-4977, ider.cs@gmail.com				   //
/////////////////////////////////////////////////////////////////////////
/*
 * Module Operations:
 * ==================
 * This module provides a class, MetaNavigator used to extract content
 * from metadata xml files, and analyze dependencies to generate edges
 * and add them to graph.
 *
 * Use path to the dependency as the EdgeType value.
 *
 * Public Interface:
 * =================
 * MetaNavigator nav = MetaNavigator(graph);
 * for (size_t i=0; i<files.size(); ++i) nav.BeginNavigation(files[i]);
 *
 * Required Files:
 * ===============
 * MetaNavigator.h, MetaNavigator.cpp, xmlTran.h, xmlTran.cpp
 * Graph.h
 */

#include <vector>
#include <string>
#include <fstream>
#include "Graph.h"
#include "xmlTran.h"
class MetaNavigator
{
public:
	MetaNavigator(Graph<std::string,std::string>& g):graph(g){}
	//Navigate the xml file named fileName under folderPath
	void BeginNavigation(const std::string& filePath);
	//Remove the path and file extension, return the pure file name
	std::string GetKeyName(std::string filePath);

private:
	//Extract xml file content to container
	void ExtractFileContent
		(std::string& containe, const std::string& filePath);
	//Retrieve the dependencies from xml file and print it
	void Dependencies(xmlRep& xml,std::list<std::string>& deps);
	//Generate Edges base on the dependencies and and them to Graph
	void GenerateEdges(xmlRep& xml,std::string filePath,std::list<std::string>& deps);
	//Removes all occurrences of white space characters from the beginning and end of string. 
	void Trim(std::string& value);
	//Get Path of Meta file
	std::string GetPath(xmlRep& xml);

	Graph<std::string,std::string>& graph;
	std::ifstream inf;
};


#endif