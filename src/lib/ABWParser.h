/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libabw project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef __ABWPARSER_H__
#define __ABWPARSER_H__

#include <librevenge/librevenge.h>
#include "ABWXMLHelper.h"

namespace libabw
{

class ABWCollector;

class ABWParser
{
public:
  explicit ABWParser(librevenge::RVNGInputStream *input, librevenge::RVNGTextInterface *iface);
  virtual ~ABWParser();
  bool parse();

private:
  ABWParser();
  ABWParser(const ABWParser &);
  ABWParser &operator=(const ABWParser &);

  // Helper functions

  int getElementToken(xmlTextReaderPtr reader);

  // Functions to read the AWML document structure

  bool processXmlDocument(librevenge::RVNGInputStream *input);
  void processXmlNode(xmlTextReaderPtr reader);

  void readMetadata(xmlTextReaderPtr reader);
  void readHistory(xmlTextReaderPtr reader);
  void readRevisions(xmlTextReaderPtr reader);
  void readIgnoredWords(xmlTextReaderPtr reader);
  void readStyles(xmlTextReaderPtr reader);
  void readLists(xmlTextReaderPtr reader);
  void readPageSize(xmlTextReaderPtr reader);
  void readSection(xmlTextReaderPtr reader);
  void readData(xmlTextReaderPtr reader);

  void readM(xmlTextReaderPtr reader);
  void readIw(xmlTextReaderPtr reader);
  void readVersion(xmlTextReaderPtr reader);
  void readS(xmlTextReaderPtr reader);
  void readL(xmlTextReaderPtr reader);
  void readD(xmlTextReaderPtr reader);

  void readP(xmlTextReaderPtr reader);
  void readTable(xmlTextReaderPtr reader);
  void readFrame(xmlTextReaderPtr reader);

  void readC(xmlTextReaderPtr reader);
  void readBr(xmlTextReaderPtr reader);
  void readCbr(xmlTextReaderPtr reader);
  void readPbr(xmlTextReaderPtr reader);

  librevenge::RVNGInputStream *m_input;
  librevenge::RVNGTextInterface *m_iface;
  ABWCollector *m_collector;
};

} // namespace libabw

#endif // __ABWPARSER_H__
/* vim:set shiftwidth=2 softtabstop=2 expandtab: */