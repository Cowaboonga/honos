#ifndef _POLITICAL_ACTIVITY_H_
#define _POLITICAL_ACTIVITY_H_

#include <string>
#include "Base.h"
#include "Requeriments.h"
#include "Effects.h"

namespace core{
	/**
	* Esta clase modela una actividad pol�tica ya sea un tratado o una pol�tica local.
	*/
	class PoliticalActivity{

	public:
		/**
		* Constructor.
		* @param wsName nombre de la pol�tica.
		* @param wsDescription descripci�n de la pol�tica.
		*/
		PoliticalActivity(std::wstring wsName, std::wstring wsDescription);
		
		/**
		* Destructor.
		* @param wsName nombre de la pol�tica.
		* @param wsDescription descripci�n de la pol�tica.
		* @param dMoney coste de la pol�tica por turno.
		*/
		PoliticalActivity(std::wstring wsName, std::wstring wsDescription, double dMoney);
		
		/**
		* A�adir requerimiento.
		* @param wsName par�metro al que afecta el requerimiento.
		* @param dBottom l�mite inferior.
		* @param dTop l�mite superior.
		*/
		void addRequeriment(std::wstring wsName, double dBottom, double dTop);
		
		/**
		* A�adir efecto.
		* @param wsName par�metro al que afecta el efecto.
		* @param dValue efecto por turno.		
		*/
		void addEffect(std::wstring wsName, double dValue);		

		std::wstring getName() const;

		double getMoney() const;

		std::wstring getDescription() const;
		
		/**
		* Indica si una pol�tica est� activa, es decir, si se cumplen los requerimientos.
		*/
		bool isActive() const;
		
		/**
		* Indica si una pol�tica est� firmada, es decir, si actualmente se est� aplicando.
		*/
		bool isSigned() const;

		void setActive(bool bParam);

		void setSigned(bool bParam);

		std::map<std::wstring, ReqValue> getRequeriments();

		std::map<std::wstring, double> getEffects();		

		/**
		* Destructor.
		*/
		~PoliticalActivity();

	private:
		std::wstring m_wsName;
		std::wstring m_wsDescription;
		bool m_bActive;
		bool m_bSigned;
		double m_dMoney;

		Requeriments m_requeriments;
		Effects m_effects;
	};
}
#endif
