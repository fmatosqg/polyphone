/***************************************************************************
**                                                                        **
**  Polyphone, a soundfont editor                                         **
**  Copyright (C) 2013-2020 Davy Triponney                                **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program. If not, see http://www.gnu.org/licenses/.    **
**                                                                        **
****************************************************************************
**           Author: Davy Triponney                                       **
**  Website/Contact: https://www.polyphone-soundfonts.com                 **
**             Date: 01.01.2013                                           **
***************************************************************************/

#include "tooldialog.h"
#include "abstracttoolgui.h"
#include "abstracttool.h"
#include <QGridLayout>

ToolDialog::ToolDialog(AbstractToolGui *toolGui, AbstractTool * tool, QWidget *parent) : QDialog(parent)
{
    this->setWindowFlags((windowFlags() & ~Qt::WindowContextHelpButtonHint));
    this->setWindowModality(Qt::WindowModal);

    // Connection of the GUI
    connect(toolGui, SIGNAL(validated()), this, SIGNAL(validated()));
    connect(toolGui, SIGNAL(canceled()), this, SLOT(canceled()));

    // Fill the dialog
    QGridLayout * layout = new QGridLayout(this);
    layout->setMargin(0);
    layout->addWidget(toolGui);
    this->setLayout(layout);

    // Title
    this->setWindowTitle(tool->getLabel());
}

void ToolDialog::canceled()
{
    this->close();
}
