//
//  Array+Only.swift
//  Memorize-3
//
//  Created by Revanth_Avs on 12/06/21.
//

import Foundation

extension Array {
    var only: Element? {
        count == 1 ? first : nil
    }
}
