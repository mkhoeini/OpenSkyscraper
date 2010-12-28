#ifndef OSS_TOWERSCENE_H
#define OSS_TOWERSCENE_H

#include "../../general.h"
#include "../../core/scene.h"
#include "../tower.h"
#include "../item.h"
#include "../gui/toolboxwindow.h"


namespace OSS {
	class TowerScene : public Scene {
	public:
		TowerScene();
		
		//Point of interest, i.e. the point in the world that's centered on-screen
		double2 POI;
		
		//Mouse location inside the world
		double2 previousWorldMouse;
		double2 worldMouse;
		bool mouseMoved;
		
		//Calculated culling values
		rectd visibleRect;
		recti visibleCells;
		
		//Visible items
		std::set<unsigned int> visibleFacilities;
		std::set<unsigned int> visibleTransports;
		
		//The tower currently being played
		Pointer<Tower> tower;
	
		
		//Simulation
		void advance(double dt);
		
		//Rendering
		void render();
		void renderBackground();
		void renderFacilities();
		void renderTransports();
		void renderGUI();
		
		//OpenGL State
		void onMoveOnScreen();
		void onMoveOffScreen();
		
		//Events
		bool handleEvent(CoreEvent * event);
		bool eventKeyDown(SDL_Event * event);
		bool eventMouseDown(SDL_Event * event);
		bool eventMouseUp(SDL_Event * event);
		
		
		/**
		 * Construction
		 */		
	private:
		Item::Descriptor * constructionItemDescriptor;
		recti constructionTemplate;
		
		bool isDraggingConstruction;
		recti previousConstructionTemplate;
		
		void updateConstruction();
		void startConstruction();
		void endConstruction();
		
		
		/**
		 * Uncategorized
		 */
	public:
		//Tools
		typedef enum {
			kBulldozerTool,
			kHandTool,
			kInspectTool,
			kConstructionTool
		} Tool;
		
	private:
		Tool tool;
		
	public:
		void setTool(Tool tool);
		void setConstructionTool(Item::Type itemType);
		
		ToolboxWindow toolboxWindow;
	};
}


#endif