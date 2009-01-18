#ifndef _LOCAL_POLICIES_H
#define _LOCAL_POLICIES_H

#include <string>
#include <vector>
#include "Base.h"
#include "PoliticalActivity.h"

namespace core{
	
	/**
	* Esta clase modela las actividades pol�ticas internas del pa�s del jugador.
	*/
	class LocalPolicies{

	public:
		/**
		* Constructor.
		*/
		LocalPolicies();
		
		/**
		* Destructor.
		*/
		~LocalPolicies();

		/**
		* A�ade una actividad pol�tica pasada como par�metro.
		* @param pPA puntero a PoliticalActivity
		*/
		void addPolicy(PoliticalActivity* pPA);

		/**
		* Devuelve un puntero al tratado selecionado actualmente.
		* @return puntero a PoliticalActivity
		*/
		PoliticalActivity* getCurrentTreaty();

		/**
		* Avanza m_pCurrentPolicyIter al siguiente tratado. Si no quedan m�s vuelve al inicio.
		*/
		void next();

		/**
		* Borra una pol�tica situada en la posici�n iPosition de la lista.
		* iPostion posici�n de la pol�tica a borrar.
		*/
		void deletePolicy(int iPosition);
		
		/**
		* Devuelve una lista con todas las pol�ticas locales.		
		*/
		std::vector<PoliticalActivity*> m_policyList;

	private:
		std::vector<PoliticalActivity*>::iterator m_pCurrentPolicyIter;	
	};
}
#endif