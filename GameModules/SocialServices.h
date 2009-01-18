#ifndef _SOCIAL_SERVICES_H_
#define _SOCIAL_SERVICES_H_

#include <string>
#include <vector>
#include "SocialService.h"
#include "Base.h"

namespace core{

	struct SocialServicesState{
		double dQuality;

		SocialServiceState healthCareState;
		SocialServiceState educationState;
		SocialServiceState justiceState;
	};

	/**
	* Esta clase representa los servicios sociales que ofrece el pa�s del jugador.
	*/
	class SocialServices{

	public:
		/**
		* Constructor.
		*/
		SocialServices();
		
		/**
		* A�ade un servicio social.
		* @param pSocialService puntero al servicios a a�adir.
		*/
		void addSocialService(SocialService* pSocialService);
		
		/**
		* Modifica el porcentaje del salario �ptimo que est� recibiendo el personal.
		* @param ID identificador del servicio.
		* @param dIndex double [0,1] siendo 1-> 100% del salario �ptimo.
		*/
		void setSalary(socialServiceID ID, double dIndex);
		
		/**
		* Modifica el porcentaje del gasto �ptimo que est�n recibiendo ls recursos.
		* @param ID identificador del servicio.
		* @param dIndex double [0,1] siendo 1-> 100% del gasto �ptimo.
		*/
		void setResourceCost(socialServiceID ID, double dIndex);
		
		/**
		* Devuelve el estado de la clase.
		* @return SocialServicesState.
		*/
		SocialServiceState getState(socialServiceID ID) const;
		
		/**
		* Devuelve el estado de la clase.
		* @return SocialServicesState.
		*/
		SocialServicesState getState() const;
		
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

		std::wstring toString() const;
		
		/**
		* Destructor
		*/
		~SocialServices();

	private:
		SocialServicesState m_state;
		std::vector<SocialService*> m_socialServicesList;
		double m_dQuality;

		void saveState();
	};
}
#endif
