/**
 ******************************************************************************
 *
 * @file       importexportgadgetfactory.cpp
 * @author     Edouard Lafargue Copyright (C) 2010.
 * @brief
 * @see        The GNU Public License (GPL) Version 3
 * @defgroup   importexportplugin
 * @{
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#include "importexportgadgetfactory.h"
#include "importexportgadgetwidget.h"
#include "importexportgadget.h"
#include "importexportgadgetconfiguration.h"
#include "importexportgadgetoptionspage.h"
#include <coreplugin/iuavgadget.h>

ImportExportGadgetFactory::ImportExportGadgetFactory(QObject *parent) :
        IUAVGadgetFactory(QString("ImportExportGadget"),
                          tr("Import/Export GCS Config"),
                          parent)
{
}

ImportExportGadgetFactory::~ImportExportGadgetFactory()
{
}

Core::IUAVGadget* ImportExportGadgetFactory::createGadget(QWidget *parent)
{
    ImportExportGadgetWidget* gadgetWidget = new ImportExportGadgetWidget(parent);
    return new ImportExportGadget(QString("ImportExportGadget"), gadgetWidget, parent);
}

IUAVGadgetConfiguration *ImportExportGadgetFactory::createConfiguration(const QByteArray &state)
{
    return new ImportExportGadgetConfiguration(QString("ImportExportGadget"), state);
}

IOptionsPage *ImportExportGadgetFactory::createOptionsPage(IUAVGadgetConfiguration *config)
{
    return new ImportExportGadgetOptionsPage(qobject_cast<ImportExportGadgetConfiguration*>(config));
}
