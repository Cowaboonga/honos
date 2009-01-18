#ifndef _UICOMPONENT_H_
#define _UICOMPONENT_H_

#include "EventsIDs.h"
#include "Convert.h"
#include <string>

namespace ui{

	/**
	* Esta estructura representa el estado actual del interfaz de usuario: almacena que componente est� hot, active, 
	* la posici�n actual del rat�n y los eventos generados por este. Esta informaci�n es �nica y compartida por todos
	* los componentes, por lo tanto s�lo existe un UIState en cada interfaz.
	*/
	struct UIState{	

		const WCHAR* pwcHot;
		const WCHAR* pwcActive;

		bool bLeftButtonDown;
		int iMouseXpos;
		int iMouseYpos;

		EVENT_ID evMouse;
		EVENT_ID evHot;
	}; 

	/**
	* Clase base de todos los componentes de la librer�a. Representa la unidad m�nima de funcionalidad de un elemento del interfaz de usuario.
	* 
	* La mayor parte de los m�todos de esta clase son virtuales y son redefinidos por parte de sus clases hijas, aumentado la funcionalidad en
	* todos los casos. UIComponent ofrece los atributos y funcionalidad comun a todo componente.
	*/
	class UIComponent{

	public:
		/**
		* Constructor de UIComponent.
		* @param wcpID identificador �nico del componente.
		* @param iXpos posici�n X en pixels. 
		* @param iYpos posici�n Y en pixels.
		* @param iHeight altura en pixels.
		* @param iWidth aanchura en pixels.
		*/
		UIComponent(const WCHAR* wcpID, int iXpos = 0,int iYpos = 0, int iHeight = 0, int iWidth = 0);

		/**
		* Destructor.
		*/
		virtual ~UIComponent(void);	

		/**
		* Manejador de los eventos generados por el interfaz de usuario.	
		* @param pUIState puntero a la estructura que guarda el estado del interfaz.
		* @return evento respuesta del componente.	
		*/
		virtual EVENT_ID OnMouseAction(UIState* pUIState);	

		/**
		* Modifica el valor de una propiedad del componente si existe.
		* @param wsName nombre de la propiedad.
		* @param wsValue cadena que representa el nuevo valor de la propiedad.
		* @return true si la propiedad existe | false en otro caso.
		*/
		virtual bool setProperty(std::wstring wsName, std::wstring wsValue);

		/**
		* Accede al valor de una propiedad del componente si existe y coloca su valor en una direcci�n de memoria indicada.
		* @param wsName nombre de la propiedad.
		* @param pdValue direcci�n donde guardar el valor de la propiedad.
		* @return true si la propiedad existe | false en otro caso.	
		*/
		virtual bool getProperty(std::wstring wsName, int* piValue);	

		/**
		* Accede al valor de una propiedad del componente si existe y coloca su valor en una direcci�n de memoria indicada.
		* @param wsName nombre de la propiedad.
		* @param pdValue direcci�n donde guardar el valor de la propiedad.
		* @return true si la propiedad existe | false en otro caso.	
		*/
		virtual bool getProperty(std::wstring wsName, double* pdValue);	

		/**
		* No hace nada. Se redefine en las clases hijas
		*/
		virtual void draw();

		/**
		* Devuelve el identificador �nico del component.
		* @return const wchar*
		*/
		const WCHAR* getID() const;	

		/**
		* Indica si cierta posici�n coincide sobre el componente.
		* @param iXpos coordenada X de la posici�n a comprobar.
		* @param iYpos coordenada Y de la posici�n a comprobar.
		* @return true si la posici�n esta sobre el componente | false en otro caso.
		*/
		bool isOver(int iXpos, int iYPos) const;

		/**
		* Devuelve el ancho del componente en pixels.
		* @return ancho del componente, en pixels.
		*/
		int getWidth() const;

		/**
		* Devuelve el largo del componente en pixels.
		* @return largo del componente, en pixels.
		*/
		int getHeight() const;

		/**
		* Devuelve la posici�n X del componente en pixels.
		* @return posici�n X del componente en pixels.
		*/
		int getXPosition() const;

		/**
		* Devuelve la posici�n Y del componente en pixels.
		* @return posici�n Y del componente en pixels.
		*/
		int getYPosition() const;
		
		/**
		* Devuelve si el elemento es o no visible.
		* @return true si es visible | false en otro caso.
		*/
		bool isVisible() const;

		/**
		* Modifica la posici�n X de pintado.
		* @param iXpos posici�n X, en pixels.
		*/
		void setXPosition(int iXpos);

		/**
		* Modifica la posici�n Y de pintado.
		* @param iYpos posici�n Y, en pixels.
		*/
		void setYPosition(int iYpos);

		/**
		* Modifica el ancho del componente.
		* @param iWidth nuevo ancho en pixels.
		*/
		void setWidth(int iWidth);	

		/**
		* Modifica el alto del componente.
		* @param iHeight nuevo ancho en pixels.
		*/
		void setHeight(int iHeight);
		
		/**
		* Modifica la visibilidad del componente.
		* @param estado del componente: true visible | false no visible.
		*/
		void setVisible(bool bVisible);

	private:
		int m_iXpos;
		int m_iYpos;	
		int m_iHeight;
		int m_iWidth;
		bool m_bVisible;

		std::wstring m_wsID;	
	};
}
#endif
