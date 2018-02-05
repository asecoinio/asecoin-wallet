// Copyright (c) 2015-2017, The Asecoin developers
//
// This file is part of Asecoin.
//
// Asecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Asecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Asecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <QHeaderView>

namespace WalletGui {

class PoolHeaderView : public QHeaderView {
  Q_OBJECT
  Q_DISABLE_COPY(PoolHeaderView)

public:
  explicit PoolHeaderView(QWidget* _parent);
  ~PoolHeaderView();

protected:
  void paintSection(QPainter* _painter, const QRect& _rect, int _logicalIndex) const override;
};

}
