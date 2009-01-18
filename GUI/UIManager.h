#ifndef _UIMANAGER_H_
#define _UIMANAGER_H_

#include <map>
#include <list>
#include "EventsIDs.h"
#include "UIComponent.h"

namespace ui{

	/**
	* Esta estructura almacena la infomaci�n sobre un evento: tipo e identificador del componente que lo provoco.
	*/
	struct EventListNode{
		EVENT_ID eventID;
		const WCHAR* pwcComponentID;
	};

	/**
	* Esta clase se encarga de agrupar y gestionar todos lo componentes que conforman el interfaz de usuario.
	* 
	* UIManager mantiene un registro de los componentes creados, traduce los eventos generados por el hardware en informaci�n que los componentes
	* pueden procesar, env�a dicha informaci�n a los componente ya actua como puente para la intercomunicaci�n de los mismos. Adem�s define y 
	* controla la posici�n Z de los componentes.
	* 
	*/
	class UIManager{

	public:
		/**
		* Constructor de UIManager.
		*/
		UIManager(void);

		/**
		* Registra un componente creado y le asigna una posici�n Z. Se asegura de que no se insertes componentes con el mismo identificador.
		* @param pUIComponent puntero al componente.
		* @param iZpos posici�n Z.
		*/
		void addUIComponent(UIComponent* pUIComponent, int iZpos);

		/**
		* Elimina un componente del registro y se asegura de que se liberen los recursos.
		* @param pUIComponent puntero al componente.	
		*/
		void deleteUIComponent(UIComponent* pUIComponent);

		/**
		* Elimina un componente del registro y se asegura de que se liberen los recursos.
		* @param wsUIComponentID identificador del componente.	
		*/
		void deleteUIComponent(std::wstring  wsUIComponentID);	

		/**
		* Elimina un componente del registro y se asegura de que se liberen los recursos.
		* @param pwcUIComponentID identificador del componente.	
		*/
		void deleteUIComponent(WCHAR* pwcUIComponentID);

		/**
		* Modifica la posici�n Z de un componente.
		* @param wsComponetID identificador del componente.	
		* @param iZValue nueva posici�n Z.
		*/
		void changeUIComponentZ(std::wstring wsComponetID, int iZValue);

		/**
		* Modifica el valor de una propiedad del componente si existe.
		* @param wsComponetID identificador del componente.	
		* @param wsName nombre de la propiedad.
		* @param wsValue cadena que representa el nuevo valor de la propiedad.
		* @return true si la propiedad existe | false en otro caso.
		* @see UIComponent
		*/
		bool setProperty(std::wstring wsComponentID, std::wstring wsName, std::wstring wsValue);	

		/**
		* Accede al valor de una propiedad del componente si existe y coloca su valor en una direcci�n de memoria indicada.
		* @param wsComponetID identificador del componente.	
		* @param wsName nombre de la propiedad.
		* @param pdValue direcci�n donde guardar el valor de la propiedad.
		* @return true si la propiedad existe | false en otro caso.
		* @see UIComponent
		*/
		bool getProperty(std::wstring wsComponentID, std::wstring wsName, int* piValue);

		/**
		* Accede al valor de una propiedad del componente si existe y coloca su valor en una direcci�n de memoria indicada.
		* @param wsComponetID identificador del componente.	
		* @param wsName nombre de la propiedad.
		* @param pdValue direcci�n donde guardar el valor de la propiedad.
		* @return true si la propiedad existe | false en otro caso.
		* @see UIComponent
		*/
		bool getProperty(std::wstring wsComponentID, std::wstring wsName, double* piValue);

		void drawUI();

		/**
		* Cambia el valor de la posici� Z de un UIComponent para que se pinte por encima del resto.
		*
		* @param pUIComponent puntero al UIComponent que se quiere llevar al frente.
		* @return entero con la diferencia entre la antigua y la nueva Z.
		*/
		int moveToFront(UIComponent* pUIComponent);

		/**
		* Procesa las se�ales emitidas por el rat�n y las evnv�a todos los componentes de la interfaz de usuario.
		* @param bLeftButtonDown true si el bot�n izquierdo del rat�n est� pulsado.
		* @param bRightButtonDown true si el bot�n derecho del rat�n est� pulsado.
		* @param bMiddleButtonDown true si el bot�n central del rat�n est� pulsado.
		* @param nMouseWheelDelta n�mero de pasos de la rueda del rat�n.
		* @param iXpos posici�n X del rat�n.
		* @param iYpos psici�n Y del rat�n.
		* @return n�mero de eventos nuevos a�adidos a la lista de eventos (m_eventList).
		*/
		int OnMouseAction(bool bLeftButtonDown, bool bRightButtonDown, bool bMiddleButtonDown, int nMouseWheelDelta, int iXpos, int iYpos);

		std::list<EventListNode>* getEventList();

		/**
		* Destructor.
		*/
		~UIManager(void);

	private:	
		std::multimap<int,UIComponent*> m_componentList;
		std::list<EventListNode> m_eventList;
		UIState m_uistate;	
	};
}
#endif