#ifndef _POPULATION_H_
#define _POPULATION_H_

#include <vector>
#include <string>
#include "PopulationGroup.h"
#include "Base.h"

namespace core{

	struct PopulationState{
		double dFoodConsumption;
		double dEnergyConsumption;
		double dManufacturedConsumption;	
		double dLastTurnHappiness;
		double dSize;
		double dConsumptionPower;
		double dHappiness;

		PopulationGroupState conservativesState;
		PopulationGroupState ultrademocratsState;
		PopulationGroupState aislandersState;
		PopulationGroupState merchantsState;
		PopulationGroupState greensState;
	};
	
	/**
	* Esta clase modela la poblaci�n que conforma el pa�s del jugador.
	*/
	class Population{

	public:
		/**
		* Constructor.
		* @param iSize tama�o de la poblaci�n.
		*/
		Population(int iSize);	

		void addPopulationGroup(PopulationGroup* pPopulationGroup);

		/**
		* Calcula el consumo de la poblaci�n dados ciertos par�metros.
		* @param ID identificador del producto.
		* @param dPriceVariation variaci�n de precio.
		* @param dPPS poder de la producci�n.
		*/
		void setConsumption(productID ID,double dPriceVariation, double dPPS);	
		
		/**
		* Asigna un valor a una propiedad del objeto especificada (si existe).
		* @param wsName nombre de la propiedad.
		* @param dValue valor a asignar.
		*/
		void setSocialServiceQuality(socialServiceID ID,double dQuality);	
		
		/**
		* Asigna un valor a una propiedad del objeto especificada (si existe).
		* @param wsName nombre de la propiedad.
		* @param dValue valor a asignar.
		*/
		void setProperty(std::wstring wsName, double dValue);
		
		/**
		* Actualiza para avanzar al siguiente turno.
		*/
		void update();	
		
		/**
		* Devuelve el tama�o de la poblaci�n
		*/ 
		int getSize() const;
		
		/**
		* Devuelve el estado de la clase.
		* @return PopulationState.
		*/
		PopulationState getState() const;

		std::wstring toString() const;
		
		/**
		* Destructor.
		*/
		~Population();

	private:
		PopulationState m_populationState;
		double m_dHappiness;
		double m_dFoodConsumption;
		double m_dEnergyConsumption;
		double m_dManufacturedConsumption;

		std::vector<PopulationGroup*> m_populationGroupList;
		int m_iSize;

		void saveState();
	};
}
#endif