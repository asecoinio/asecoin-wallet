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

#include <QFrame>

class QAbstractItemModel;
class QAbstractProxyModel;

namespace Ui {
  class TransactionTransfersRenderer;
}

namespace WalletGui {

class IAddressBookManager;
class ICryptoNoteAdapter;

class TransactionTransfersRenderer : public QFrame {
  Q_OBJECT
  Q_DISABLE_COPY(TransactionTransfersRenderer)

public:
  explicit TransactionTransfersRenderer(ICryptoNoteAdapter* _cryptoNoteAdapter, IAddressBookManager* _addressBookManager, const QModelIndex& _transactionIndex,
    const QString& _walletAddress, QWidget* _parent);
  ~TransactionTransfersRenderer();

  static int calculateItemHeight(quintptr _transferCount);

private:
  QScopedPointer<Ui::TransactionTransfersRenderer> m_ui;
};

}
