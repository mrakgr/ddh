#ifndef WARTHOG_SCENARIOMANAGER_H
#define WARTHOG_SCENARIOMANAGER_H

// scenario_manager.h
//
// A note on .scenario versions:
//
//	v1.0 Generated by HOG; order:
//		bucket,map,mapwidth,mapheight,sx,sy,gx,gy,distance
//	v3.0: Generated by scenario_manager: order: sx,sy,gx,gy,distance,map
//
// @author: dharabor
// @created: 21/08/2012
//

#include "experiment.h"
#include "gridmap.h"

#include <vector>
#include <fstream>
#include <iostream>

namespace warthog
{

class scenario_manager 
{
	public:
		scenario_manager();
		~scenario_manager();

		inline experiment* 
		get_experiment(unsigned int which) 
		{ 
			if(which < experiments_.size())
			{
				return experiments_[which]; 
		   	}
			return 0;
		}

		inline void 
		add_experiment(experiment* newexp) 
		{ 
			experiments_.push_back(newexp); 
		}

		inline unsigned int 
		num_experiments() 
		{ 
			return experiments_.size(); 
		}
		
		void generate_experiments(warthog::gridmap*, int num);
		void load_scenario(const char* filelocation);
		void write_scenario(const char* filelocation);
		void clear() { experiments_.clear(); }
		void sort(); // organise by increasing solution length

	private:
		experiment* generate_single_experiment(warthog::gridmap*);
		void load_v1_scenario(std::ifstream& infile);
		void load_v3_scenario(std::ifstream& infile);

		std::vector<warthog::experiment*> experiments_;		
		int version_;
};

}

#endif

