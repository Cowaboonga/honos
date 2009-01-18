#ifndef _FOREIGN_COUNTRY_H_
#define _FOREIGN_COUNTRY_H_

#include <string>
#include <vector>
#include "Base.h"
#include "PoliticalActivity.h"

namespace core{

	struct ForeignCountryState{
		double dOpinon;
	};

	/**
	* Esta clase define un estado no manejado por el jugador.
	*/
	class ForeignCountry{

	public:
		ForeignCountry(const wchar_t* pwcName, double dProductionImportance, double dSocialServicesImportance, double dPopulationImportance);
		
		/**
		* A�ade una actividad pol�tica pasada como par�metro.
		* @param pPA puntero a PoliticalActivity
		*/
		void addTreaty(PoliticalActivity* pPA);
		
		/**
		* Actualiza el estado del pa�s.
		*/ 
		void update();
		
		/**
		* Calcula la opini�n de la potencia extranjera respecto al estado del pa�s del jugador.
		* @param dProductionState estado de la producci�n.
		* @param dSocialServicesState estado de los servicios sociales.
		* @param dPopulationState estado de la poblaci�n.
		*/
		double calculateOpinion(double dProductionState, double dSocialServicesState, double dPopulationState);
		
		/**
		* Devuelve una lista con los tratados posibles para el pa�s.
		* @return std::vector<PoliticalActivity*>
		*/
		std::vector<PoliticalActivity*> getPossibleTreatyList();
		
		/**
		* Devuelve una lista con los tratados activos para el pa�s.
		* @return std::vector<PoliticalActivity*>
		*/
		std::vector<PoliticalActivity*> getActiveTreatyList();
		
		/**
		* Devuelve un puntero al tratado selecionado actualmente.
		* @return puntero a PoliticalActivity
		*/
		PoliticalActivity* getCurrentTreaty();
		
		/**
		* Avanza currentTreaty al siguiente tratado. Si no quedan m�s vuelve al inicio.
		*/
		void next();
		
		/**
		* Devuelve el estado de la clase.
		* @return ForeignCountryState.
		*/
		ForeignCountryState getState() const;

		std::wstring toString() const;
		
		/**
		* Destructor.
		*/
		~ForeignCountry();
		
		std::vector<PoliticalActivity*> m_treatyList;
	private:
		ForeignCountryState m_state;		
		std::wstring m_wsName;
		std::wstring m_wsDescription;
		
		double m_dOpinion;
		double m_dProductionImportance;
		double m_dPopulationImportance;
		double m_dSocialServicesImportance;

		std::vector<PoliticalActivity*>::iterator m_pCurrentTreatyIter;

		void saveState();
	};
}
#endif