/*
 *  COMP 15 Project 2
 *
 *  SixDegrees.cpp
 * 
 *  PURPOSE: The main driver class for the SixDegrees program. Includes all
 *  functions to populate and interact with the CollabGraph
 *
 *  Modified By: Dylan Maloy
 *           On: NOV 18 2020
 */

#include "SixDegrees.h"
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>

using namespace std;

// default constructor
SixDegrees::SixDegrees() {}

// defualt destructor
SixDegrees::~SixDegrees() {}

/**
FUNCTION: run
PURPOSE: populates the graph and runs the query
PARAMETERS: cmdfile: command file
RETURN: void
MISC: N/A
**/
void SixDegrees::run(string inputfile, string cmdfile, string outputfile)
{
        if (outputfile != "")
        {
                const char *cArr = outputfile.c_str();
                remove(cArr); // remove file & its contents before re-creating
                freopen(cArr, "a", stderr);
                freopen(cArr, "a", stdout);
        }

        populateGraph(inputfile);

        if (cmdfile == "testing")
        {
                return;
        }
        else if (cmdfile != "")
        {
                openFileAndRead(cmdfile);
        }
        else
        {
                parseCommand(cin);
        }
        if (outputfile != "")
        {
                fclose(stderr);
                fclose(stdout);
        }
}

/**
FUNCTION: parseCommand
PURPOSE: chooses the correct execution flow given the input
PARAMETERS: in: input stream
RETURN: void
MISC: N/A
**/
void SixDegrees::parseCommand(istream &in)
{
        string cmd, a1, a2, curStr;
        vector<string> excl;
        getline(in, cmd);
        if (cmd == "quit") return;
        getline(in, a1);
        getline(in, a2);
        if (cmd == "not")
        {
                while (curStr != "*")
                {
                        getline(in, curStr);
                        if (curStr != "*")
                                excl.push_back(curStr);
                }
        }
        chooseCmd(cmd, a1, a2, excl);
        parseCommand(in);
}

/**
FUNCTION: openFileAndRead
PURPOSE: opens th file and calls readFromFile
PARAMETERS: cmdf: file name
RETURN: void
MISC: N/A
**/
void SixDegrees::openFileAndRead(string cmdf) {
        ifstream cmdfile(cmdf);
        if (!cmdfile.is_open()) 
        {
                cerr << cmdf << " cannot be opened." << endl;
                return;
        }
        readFromFile(cmdfile);
}

/**
FUNCTION: readFromFile
PURPOSE: chooses the correct command to execute given the parameters
PARAMETERS: cmdfile: input stream
RETURN: void
MISC: N/A
**/
void SixDegrees::readFromFile(ifstream &cmdfile)
{
        string cmd, out, a1, a2;
        vector<string> excl;
        getline(cmdfile, out);
        while (out != "quit" && !cmdfile.eof())
        {
                cmd = out;
                if (cmd != "not" && cmd != "bfs" && cmd != "dfs")
                {
                        cerr << cmd << " is not a command. Please try again."
                        << endl;
                }
                else
                {
                        getline(cmdfile, a1);
                        getline(cmdfile, a2);
                        if (out == "not")
                        {
                                while (out != "*")
                                {
                                        getline(cmdfile, out);
                                        if (out != "*") excl.push_back(out);
                                }
                        }
                        chooseCmd(cmd, a1, a2, excl);
                }
                getline(cmdfile, out);
        }
}

/**
FUNCTION: chooseCmd
PURPOSE: chooses correct cmd given input
PARAMETERS: filename: name of file containing artists
RETURN: void
MISC: N/A
**/
void SixDegrees::chooseCmd(string cmd, string a1, string a2, vector<string> e)
{
        try
        {
                if (cmd == "bfs")
                {
                        bfs(a1, a2);
                }
                else if (cmd == "dfs")
                {
                        dfs(a1, a2);
                }
                else
                {
                        excl(a1, a2, e);
                }
                cout << "***" << endl;
        }
        catch (out_of_range e)
        {
                cerr << e.what() << endl;
        }
}

/**
FUNCTION: populateGraph
PURPOSE: populates the graph from the artists.txt file
PARAMETERS: filename: name of file containing artists
RETURN: void
MISC: N/A
**/
void SixDegrees::populateGraph(string filename)
{
        unordered_map<string, vector<string>> map;
        ifstream artists(filename);
        string artist;
        while (getline(artists, artist))
        {
                Artist a(artist);
                if (artistMap.find(artist) == artistMap.end())
                {
                        artistMap[artist] = a;
                        graph.insert_vertex(artistMap[artist]);
                        getline(artists, artist);
                        while (artist != "*")
                        {
                                artistMap[a.get_name()].add_song(artist);
                                if (map.find(artist) != map.end())
                                {
                                        map[artist].push_back(a.get_name());
                                }
                                else
                                {
                                        map[artist] =
                                            vector<string>{a.get_name()};
                                }
                                getline(artists, artist);
                        }
                }
        }
        connectGraph(map);
}

/**
FUNCTION: connectGraph
PURPOSE: connects the verticies on the existing graph
PARAMETERS: map: pre-existing map of artists and songs
RETURN: void
MISC: N/A
**/
void SixDegrees::connectGraph(unordered_map<string, vector<string>> map)
{
        for (auto const &song : map)
        {
                vector<string> artVec = song.second;
                for (int j = 0; j < (int)artVec.size() - 1; j++)
                {
                        for (int i = j + 1; i < (int)artVec.size(); i++)
                        {
                                createConnection(artVec.at(j),
                                                 artVec.at(i), song.first);
                        }
                }
        }
}

/**
FUNCTION: createConnection
PURPOSE: connects two verticies to eachother
PARAMETERS: a1: first artist, a2: second artist, song: song name
RETURN: void
MISC: N/A
**/
void SixDegrees::createConnection(string a1, string a2, string song)
{
        if (a1 != a2)
        {
                graph.insert_edge(artistMap[a1],
                                  artistMap[a2], song);
                graph.insert_edge(artistMap[a2],
                                  artistMap[a1], song);
        }
}

/**
FUNCTION: bfs
PURPOSE: runs bfs on the graph from a1 to a2
PARAMETERS: a1: first artist, a2: second artist
RETURN: void
MISC: N/A
**/
void SixDegrees::bfs(string a1, string a2)
{
        cout << "bfs was called." << endl;
        Artist startV = fetchArtist(a1);
        graph.mark_vertex(startV);
        Artist endV = fetchArtist(a2);
        queue<Artist> q;
        q.push(startV);
        while (!q.empty())
        {
                Artist curNode = q.front();
                q.pop();
                vector<Artist> neighbors = graph.get_vertex_neighbors(curNode);
                for (int i = 0; i < (int)neighbors.size(); i++)
                {
                        Artist n = neighbors.at(i);
                        if (n.get_name() != curNode.get_name() & 
                        !graph.is_marked(n))
                        {
                                graph.set_predecessor(n, curNode);
                                graph.mark_vertex(n);
                                q.push(n);
                        }
                }
        }
        printPath(a1, a2);
}

/**
FUNCTION: dfs
PURPOSE: runs dfs on the graph from a1 to a2
PARAMETERS: a1: first artist, a2: second artist
RETURN: void
MISC: N/A
**/
void SixDegrees::dfs(string a1, string a2)
{
        cout << "dfs was called." << endl;
        Artist startV = fetchArtist(a1);
        Artist endV = fetchArtist(a2);
        stack<Artist> s;
        s.push(startV);
        while (!s.empty())
        {
                Artist curNode = s.top();
                s.pop();
                if (!graph.is_marked(curNode)) graph.mark_vertex(curNode);
                vector<Artist> neighbors = graph.get_vertex_neighbors(curNode);
                for (int i = 0; i < (int)neighbors.size(); i++)
                {
                        Artist n = neighbors.at(i);
                        if (!graph.is_marked(n))
                        {
                                graph.set_predecessor(n, curNode);
                                graph.mark_vertex(n);
                                s.push(n);
                        }
                }
        }
        printPath(a1, a2);
}

/**
FUNCTION: excl
PURPOSE: gets shortest path while excluding certain vertices
PARAMETERS: a1: first artist, a2: second artist, excl: vector of vertices to 
            exclude
RETURN: void
MISC: N/A
**/
void SixDegrees::excl(string a1, string a2, vector<string> excl)
{
        cout << "not was called." << endl;
        Artist startV = fetchArtist(a1);
        graph.mark_vertex(startV);
        Artist endV = fetchArtist(a2);
        queue<Artist> q;
        q.push(startV);
        while (!q.empty())
        {
                Artist curNode = q.front();
                q.pop();
                vector<Artist> neighbors = graph.get_vertex_neighbors(curNode);
                for (int i = 0; i < (int)neighbors.size(); i++)
                {
                        Artist n = neighbors.at(i);
                        if (find(excl.begin(), excl.end(),
                                 n.get_name()) != excl.end())
                        {
                                graph.mark_vertex(n);
                        }
                        else if (n.get_name() != curNode.get_name() 
                                && !graph.is_marked(n))
                        {

                                graph.set_predecessor(n, curNode);
                                graph.mark_vertex(n);
                                q.push(n);
                        }
                }
        }
        printPath(a1, a2);
}

/**
FUNCTION: printPath
PURPOSE:  prints the path from vertex a to vertex b
PARAMETERS: v1: starting vertex, v2: destination vertex
RETURN: void
MISC: N/A
**/
void SixDegrees::printPath(string v1, string v2)
{
        Artist startV = artistMap[v1];
        Artist endV = artistMap[v2];
        Artist next;
        stack<Artist> path = graph.report_path(startV, endV);
        if (path.empty())
        {
                string q(1, '"');
                throw out_of_range("A path does not exist between " + q + v1 +
                                   q + " and " + q + v2 + q + ".");
        }
        else
        {
                path.pop(); // knock off startV
                while (!path.empty())
                {
                        next = artistMap[path.top().get_name()];
                        cout << '"' << startV.get_name() << '"'
                             << " collaborated with "
                             << '"' << next.get_name() << '"'
                             << " in "
                             << '"' << graph.get_edge(startV, next) << '"'
                             << "."
                             << endl;
                        startV = next;
                        path.pop();
                }
        }
        graph.clear_metadata();
}

/**
FUNCTION: fetchArtist
PURPOSE:  gets the artist object given a string
PARAMETERS: artist: artist name
RETURN: Artist
MISC: N/A
**/
Artist SixDegrees::fetchArtist(string artist)
{
        if (artistMap.find(artist) == artistMap.end())
        {
                throw out_of_range('"' + artist + '"' +
                                   " was not found in the dataset :(");
        }
        else
        {
                return artistMap[artist];
        }
}