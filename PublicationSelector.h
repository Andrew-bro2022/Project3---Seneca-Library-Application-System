// PublicationSelector
// File PublicationSelector.h
// Full Name  : Yuchi Zheng


#ifndef SDDS_PUBLICATIONSELECTOR_H
#define SDDS_PUBLICATIONSELECTOR_H
#include "Publication.h"
namespace sdds {
   class PublicationSelector {
      const int allocationUnit{ 10 };
      const int m_pageSize{ };
      const Publication** m_pub{};//addresses of a selection of the Publications(array)          
      char m_title[81]{};
      int m_currentPage{ 1 };
      int m_arraySize{};
      int m_noOfPubs{};
      void display(int page)const;
      int getSelectedLibRef()const;
   public:
      PublicationSelector(const char* title = "Select a publication: ", int pageSize = 15);
      ~PublicationSelector();
      PublicationSelector(const PublicationSelector&) = delete;
      PublicationSelector& operator=(const PublicationSelector&) = delete;
      // adds publication to the menu by address
      PublicationSelector& operator<<(const Publication* pub);
      // add publication to the menu by reference
      PublicationSelector& operator<<(const Publication& pub);
      // return true menu is not empty 
      operator bool()const;
      // clears all the publications and sets the selector empty and ready to be refilled
      void reset(); 
      // sorts the selections based on date and title
      void sort();
      // runs the selection return the library reference of the selection publication.
      int run();
   };
}
#endif // !SDDS_PUBLICATIONSELECTOR_H
